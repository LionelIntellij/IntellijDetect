#include "InputImage.h"
#include <cstdio>
#include <cstdlib>

//Methods


InputImage::InputImage(int height, int width, int channel):myHeight(height),
												 myWidth(width),
												 myChannel(channel),
												 myData(nullptr)
{
	allocate();
}

double& InputImage::operator() (int indexChannel, int indexHeigth ,int indexWidth)
{
	return myData[indexChannel*myWidth*myHeight + indexHeight*myWidth +
				indexWidth];
}

double InputImage::operator() (int indexChannel, int indexHeigth ,int indexWidth) const
{
	return myData[indexChannel*myWidth*myHeight + indexHeight*myWidth +
				indexWidth];
}

void InputImage::fillImage(float value)
{
for(int index = 0; index < height*width*channel; ++index)
	myData[index] = value;
}

void InputImage::allocate()
{
	freeImage();
	data = new double(myHeight*myWidth*myChannel);
	memset(data,0,myHeight*myWidth*myChannel*sizeof(double));
}

void InputImage::freeImage()
{
	if(myData)
		delete myData;
}

InputImage::~InputImage()
{
	freeImage();
}


