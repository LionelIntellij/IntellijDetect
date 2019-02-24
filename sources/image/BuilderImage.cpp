#include "BuilderImage.h"

BuilderImage::BuilderImage(const QImage & image)
{
	convertToMat(image);
	iplToImage(imageIpl);
}

BuilderImage::~BuilderImage()
{
	delete myImage;
}

BuilderImage::iplToImage(cv::Mat & image)
{
	IplImage * imageIpl = cvDecodeImage(&image);
	myImage = new Image(imageIpl.height ,imageIpl.width,imageIpl.nChannels);
	unsigned char * data = (unsigned char *)imageIpl.imageData;
	for(int indexHeight = 0; indexHeight < myHeight; ++indexHeight)
	{
		for(int indexChannel = 0; indexChannel < myChannel ; ++indexChannel)
		{
			for(int indexWidth = 0; indexWidth < myWidth ; ++indexWidth)
			{
				myData(indexChannel,indexHeight,indexWidth) = data[indexHeight*step
																+ indexWidth*myChannel
																+ indexChannel]/255.;
			}
		}
	}
	cvRelease(&imageIpl);
}

void BuilderImage::EmbedImage()
{

}

InputImage * BuilderImage::getResult()
{
	return convertToImage();
}

void BuilderImage::convertToMat(const QImage &image)
{
	myMatImage = cv::Mat(image.height(),image.width(),
								CV_8UC3,image.bits(),
								image.bytesPerLine());
	cv::cvtColor(myMatImage, myMatImage, CV_RGB2BGR);
}
