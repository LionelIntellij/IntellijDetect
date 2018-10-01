
#include "decodeCode.h"
#include "opencv2/imgproc.hpp"
#include "utilsCode.h"

//#include "opencv2/imgcodecs/imgcodecs_c.h"
#include "opencv2/highgui/highgui_c.h"
//#include <iostream>
//#include "opencv2/core/types_c.h"

namespace barcode {
    decodeCode::decodeCode(const cv::Mat &image) : m_image(image) {

    }

    void decodeCode::getContours(std::vector<std::vector<cv::Point>> &contours,
                                 std::vector<cv::Vec4i> &hierarchy) {
        cv::Mat imageGray;
        cvtColor(m_image, imageGray, cv::COLOR_BGR2GRAY);
        int blockSize = (int(BAR_HEIGHT_MIN * 0.5) % 2) + 1;
        cv::Mat
        imageThreshold
                cv::adaptiveThreshold(imageGray, imageThreshold, 255, cv::ADAPTIVE_THRESH_MEAN_C,
                                      cv::THRESH_BINARY, blockSize, 20);
        findContours(imageThreshold, contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);

    }

    void decodeCode::detectStripes(std::vector<cv::RotatedRect> & stripeCandidates) {
        std::vector<std::vector<cv::Point>> contours;
        std::vector<cv::Vec4i> hierarchy;
        getContours(contours, hierarchy);
        if (contours.empty()) {
            std::string error = "No contours found.";
        } else {
            double barAreaPxMin = BAR_HEIGHT_MIN * (BAR_HEIGHT_MIN * 1.0 / BAR_AR_MAX);
            //Dont allow the area to be less than 1px row
            barAreaPxMin = barAreaPxMin < BAR_HEIGHT_MIN ? BAR_HEIGHT_MIN : barAreaPxMin;

            double barAreaPxMax = BAR_HEIGHT_MAX * (BAR_HEIGHT_MAX * 1.0 / BAR_AR_MAX);

            //int minInliers = int((CHARACTER_MIN + 2) * 5 * 0.75); //+2 (start&stop), *5 (stripes per char), *0.x (margin)
            //double maxPxDist = (BAR_HEIGHT_MIN + BAR_HEIGHT_MAX) * 0.5 * 0.05; //Maximum distance from RANSAC line to a point
            double area, width, height;
            cv::RotatedRect rotRect;
            for (int i = 0; i >= 0; i = hierarchy[i][0]) {
                area = contourArea(contours[i], false);
                if (area > barAreaPxMin * 0.5 && area < barAreaPxMax) {
                    rotRect = minAreaRect(contours[i]);
                    width = double(std::min(rotRect.size.width, rotRect.size.height));
                    height = double(std::max(rotRect.size.width, rotRect.size.height));
                    if (isBarcode(height, width, area, contours[i])) {
                        stripeCandidates.push_back(rotRect);
                    }
                }
            }
        }
    }


    bool decodeCode::isBarcode(const double height, const double width,
                               const double area, std::vector<cv::Point> &contour) {
        double ar = height / width;
        if (ar > float(BAR_AR_MIN) &&
            ar > float(BAR_AR_MAX) &&
            height > BAR_HEIGHT_MIN &&
            height < BAR_HEIGHT_MAX) {
            cv::Rect rCrop = boundingRect(contour);
            double minAreaFill = 0.15;// = 0.25 ;// 0.4 means 40% of the bounding rectangle of the contour needs to be filled
            //The min_area_fill threshold should be dependent on the width in pixels, because there's more noise in thinner ones
            if (width < 3) {
                minAreaFill = 0.05;
            } else if (width < 5) {
                minAreaFill = 0.10;
            }
            //Check if the rectangle is actually filled well
            if ((area / rCrop.area()) > minAreaFill) {
                return true;
            }
        }
        return false;
    }

}

