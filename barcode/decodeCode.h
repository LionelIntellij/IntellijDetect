#ifndef BARCODE_DECODE_CODE39
#define BARCODE_DECODE_CODE39

#include <vector>
#include <unordered_map>
#include <string>
#include "opencv2/opencv.hpp"

namespace barcode {

    class decodeCode {
    public:
        explicit decodeCode(const cv::Mat &image);


        virtual void decodeBinary() = 0;

    protected:
        //attribut
        cv::Mat m_image;

        //method
        void getContours(std::vector<std::vector<cv::Point>> &contours,
                         std::vector<cv::Vec4i> &hierarchy);

        bool isBarcode(double height, double width,
                       double area, std::vector<cv::Point> &contour);

        void detectStripes(std::vector<cv::RotatedRect> & stripeCandidates);
    };
}

#endif