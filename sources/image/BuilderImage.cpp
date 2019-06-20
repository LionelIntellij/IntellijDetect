#include "BuilderImage.h"
//#include <opencv2/imgcodecs_c.h>
#include <opencv2/highgui/highgui.hpp>


BuilderImage::BuilderImage(const QImage &image)
{
	convertToMat(image);
	iplToImage();
	
}


void BuilderImage::iplToImage()
{
	CvMat matAPI(myMatImage);
	IplImage *imageIpl = cvDecodeImage(&matAPI, CV_LOAD_IMAGE_COLOR);
	myImage = InputImage(imageIpl->height, imageIpl->width, imageIpl->nChannels);
	auto data = (unsigned char *) imageIpl->imageData;
	for (int indexHeight = 0; indexHeight < myImage.getHeight(); ++indexHeight)
	{
		for (int indexChannel = 0; indexChannel < myImage.getChannel(); ++indexChannel)
		{
			for (int indexWidth = 0; indexWidth < myImage.getWidth(); ++indexWidth)
			{
				myImage(indexChannel, indexHeight, indexWidth) =
					static_cast<float>(data[indexHeight * imageIpl->widthStep
						+ indexWidth * myImage.getChannel()
						+ indexChannel] / 255.);
			}
		}
	}
	cvReleaseImage(&imageIpl);
}


void BuilderImage::resizeVertical(const int width, InputImage &resizedImage)
{
	float widthScale = (float) (myImage.getWidth() - 1) / (width - 1);
	float value = 0;
	for (int indexChannel = 0; indexChannel < myImage.getChannel(); ++indexChannel)
	{
		for (int indexHeight = 0; indexHeight < myImage.getHeight(); ++indexHeight)
		{
			for (int indexWidth = 0; indexWidth < width; ++indexWidth)
			{
				if (indexWidth == width - 1 || width == 1)
				{
					value = myImage(myImage.getWidth() - 1, indexHeight, indexWidth);
				}
				else
				{
					float scale = indexWidth * widthScale;
					int scaleRounded = (int) scale;
					float deltaScale = scale - scaleRounded;
					value = (1 - deltaScale) * myImage(indexHeight, scaleRounded, indexChannel)
						+ deltaScale * myImage(indexHeight, scaleRounded, indexChannel);
				}
				resizedImage(indexHeight, indexWidth, indexChannel) = value;
			}
		}
	}
}


void BuilderImage::resizeHorizontal(const int height, const InputImage &imageBase, InputImage &resizedImage)
{
	float heigthScale = (float) (myImage.getHeight() - 1) / (height - 1);
	for (int indexChannel = 0; indexChannel < myImage.getChannel(); ++indexChannel)
	{
		for (int indexHeight = 0; indexHeight < height; ++indexHeight)
		{
			float scale = indexHeight * heigthScale;
			int scaleRounded = (int) scale;
			float deltaScale = scale - scaleRounded;
			for (int indexWidth = 0; indexWidth < imageBase.getWidth(); ++indexWidth)
			{
				float value = (1 - deltaScale) * myImage(indexHeight, indexWidth, indexChannel);
				resizedImage(indexHeight, indexWidth, indexChannel) = value;
			}
			if (indexHeight != height - 1 && myImage.getHeight() != 1)
			{
				for (int indexWidth = 0; indexWidth < imageBase.getWidth(); ++indexWidth)
				{
					float value = deltaScale * myImage(indexHeight + 1, indexWidth, indexChannel);
					resizedImage(indexHeight, indexWidth, indexChannel) += value;
				}
			}
		}
	}
}


void BuilderImage::resizeImage(const int height, const int width)
{
	InputImage resizedVertical(myImage.getHeight(), width, myImage.getChannel());
	resizeVertical(width, resizedVertical);
	InputImage resizedImage(height, width, myImage.getChannel());
	resizeHorizontal(height, resizedVertical, resizedImage);
	myImage.freeImage();
	resizedVertical.freeImage();
	myImage = resizedImage;
	resizedImage.freeImage();
}


void BuilderImage::letterBox(const int height, const int width, InputImage &imageBoxed)
{
	imageBoxed.setImage(height, width, myImage.getChannel());
	int widthResized;
	int heightResized;
	if (((float) width / myImage.getWidth()) < ((float) height / myImage.getHeight()))
	{
		heightResized = width;
		widthResized = (myImage.getHeight() * width) / myImage.getWidth();
	}
	else
	{
		heightResized = height;
		widthResized = (myImage.getWidth() * height) / myImage.getHeight();
	}
	resizeImage(heightResized, widthResized);
	imageBoxed.fillImage(0.5);
	embedImage((width - widthResized) / 2, (height - heightResized) / 2, imageBoxed);
}


void BuilderImage::embedImage(const int deltaVertical, const int deltaHorizontal, InputImage &boxed)
{
	for (int indexChannel = 0; indexChannel < myImage.getChannel(); ++indexChannel)
	{
		for (int indexHeight = 0; indexHeight < myImage.getHeight(); ++indexHeight)
		{
			for (int indexWidth = 0; indexWidth < myImage.getWidth(); ++indexWidth)
			{
				float value = myImage(indexHeight, indexWidth, indexChannel);
				boxed(indexHeight + deltaHorizontal, indexWidth + deltaVertical, indexChannel) = value;
			}
		}
	}
}


void BuilderImage::convertToMat(const QImage &image)
{
	myMatImage = cv::Mat(image.height(), CV_8UC3, image.width(), const_cast<uchar*>(image.bits()));
	cv::cvtColor(myMatImage, myMatImage, cv::COLOR_RGB2BGR);
}


BuilderImage::~BuilderImage()
{
	myImage.freeImage();
}
