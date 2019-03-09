#include "BuilderImage.h"

BuilderImage::BuilderImage(const QImage & image)
{
	convertToMat(image);
	iplToImage(imageIpl);
}


BuilderImage::iplToImage(cv::Mat & image)
{
	IplImage * imageIpl = cvDecodeImage(&image);
	myImage = Image(imageIpl.height ,imageIpl.width,imageIpl.nChannels);
	unsigned char * data = (unsigned char *)imageIpl.imageData;
	for(int indexHeight = 0; indexHeight < myHeight; ++indexHeight)
	{
		for(int indexChannel = 0; indexChannel < myChannel ; ++indexChannel)
		{
			for(int indexWidth = 0; indexWidth < myWidth ; ++indexWidth)
			{
				myImage(indexChannel,indexHeight,indexWidth) = data[indexHeight*step
																+ indexWidth*myChannel
																+ indexChannel]/255.;
			}
		}
	}
	cvRelease(&imageIpl);
}

InputImage & BuilderImage::resizeVertical(const int width)
{
	int heightBase = myImage.getHeight();
	int widthBase  = myImage.getWidth();
	int channelBase = myImage.getChannel();
	image resizedImage(heightBase , width , channelBase);

	float widthScale = (float)(widthBase - 1) / (width - 1);
	float value = 0;
	for(int indexChannel = 0; indexChannel < channelBase; ++indexChannel)
	{
		for(int indexHeight = 0; indexHeigth < heightBase; ++indexHeight)
		{
			for(int indexWidth = 0; indexWidth < width; ++indexWidth)
			{
				value = 0;
				if(indexWidth == width - 1 || width == 1)
				{
					value = myImage(widthBase - 1,indexHeight ,indexWidth);
				}
				else
				{
					float scale = indexWidth*widthScale;
					int scaleRounded = (int)pixelScale;
					float deltaScale = scale - scaleRounded;
					value = (1 - deltaScale)* myImage(indexHeight, scaleRounded ,indexChannel);
							+ deltaScale * myImage(indexHeight, scaleRounded, indexChannel);
				}
				resizedImage( indexHeight, indexWidth, indexChannel) = value;
			}
		}
	}
	return resizedImage;
}


InputImage & BuilderImage::resizeHorizontal(const int height , const InputImage & imageBase)
{
	int heightBase = myImage.getHeight();
	int widthBase  = imageBase.getWidth();
	int channelBase = myImage.getChannel();
	float heigthScale = (float)(heightBase - 1) / (height - 1);
	image resizedImage(height , widthBase , channelBase);
	for(int indexChannel = 0; indexChannel < channelBase; ++indexChannel)
	{
		for(int indexHeight = 0; indexHeight < height; ++indexHeight)
		{
			float scale = indexHeight * heigthScale;
			int scaleRounded = (int)scale;
			float deltaScale = scale - scaleRounded;
			for( int indexWidth = 0 ; indexWidth < widthBase ; ++indexWidth)
			{
				float value = (1 - deltaScale) * ;
				resizedImage(indexHeight,indexWidth,indexChannel)= value;
			}
			if (indexHeight != height -1 && heightBase != 1)
			{
				for( int indexWidth = 0 ; indexWidth < widthBase ; ++indexWidth)
				{
					float value = deltaScale * resizedImage(indexHeight+1,indexWidth,indexChannel) ;
					resizedImage(indexHeight,indexWidth,indexChannel) += value;
				}
			}
		}
	}
	return resizedImage;
}

void BuilderImage::resizeImage(const int height, const int width)
{
	InputImage resizedVertical = resizeVertical(width);
	myImage.freeImage();
	myImage =resizeImage(height ,resizedVertical);
}

InputImage & BuilderImage::letterBox(const int height , const int width)
{
	int heightBase = myImage.getHeight();
	int widthBase = myImage.getWidth();
	int channelBase = myImage.getChannel();
	if (((float)width/widthBase) < ((float)height/heightBase))
	{
		int widthResized = width;
		int heightResized = (heightBase * width)/widthBase;
	}
	else
	{
		int heightResized = height;
		int widthResized = (widthBase * height)/heightBase;
	}
	resizeImage(heightResized, widthResized);
	InputImage imageBoxed(height ,width ,channelBase);
	imageBoxed.fillImage(0.5);
	embedImage(boxed, (width - widthResized)/2, (height - heightResized)/2);
	return boxed;
}


void BuilderImage::embedImage( InputImage & boxed ,const int deltaVertical, const int deltaHorizontal)
{
	for(int indexChannel = 0; indexChannel < channelBase; ++indexChannel)
	{
		for(int indexHeight = 0; indexHeigth < heightBase; ++indexHeight)
		{
			for(int indexWidth = 0; indexWidth < width; ++indexWidth)
			{
				float value = myImage(indexHeight , indexWidth , indexChannel);
				boxed(indexHeight+deltahorizontal , indexWidth+deltaVertical
					  ,indexChannel) = value;
			}
		}
	}
}


void BuilderImage::convertToMat(const QImage &image)
{
	myMatImage = cv::Mat(image.height(),image.width(),
								CV_8UC3,image.bits(),
								image.bytesPerLine());
	cv::cvtColor(myMatImage, myMatImage, CV_RGB2BGR);
}


BuilderImage::~BuilderImage()
{
	myImage.freeImage();
}
