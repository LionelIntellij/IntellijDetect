#include <QImage>
#include <opencv2/opencv.hpp>
#include "InputImage.h"


class BuilderImage{


public:
	BuilderImage(const QImage &image);
	~BuilderImage();

private:
	//attributes
	Image * myImage;
	cv::Mat myMatImage;

    //method
    QImage & convertToQImage();
	cv::Mat & convertToMat(QImage &image);
	void iplToImage(cv::Mat & Image);
};
