#include <QImage>
#include <opencv2/opencv.hpp>
#include "InputImage.h"


class BuilderImage{


public:
	BuilderImage(const QImage &image);
	~BuilderImage();

private:
	//attributes
	Image myImage;
	cv::Mat myMatImage;

    //method
	InputImage & resizeHorizontal(const int height , const InputImage & imageBase);
	InputImage & resizeVertical(const int widht);

    QImage & convertToQImage();
	void resizeImage(const int height , const int widht);
	void convertToMat(const QImage &image);
	void iplToImage(cv::Mat & Image);
};
