#include "InputImage.h"
#include <cstdio>
#include <cstdlib>

//Methods

InputImage::InputImage() : myData(nullptr)
{
};


void InputImage::setImage(int height, int width, int channel)
{
	myHeight = height;
	myWidth = width;
	myChannel = channel;
	allocate();
}


InputImage::InputImage(int height, int width, int channel) : myData(nullptr)
{
	setImage(height, width, channel);
}


float &InputImage::operator()(int indexChannel, int indexHeight, int indexWidth)
{
	return myData[indexChannel * myWidth * myHeight + indexHeight * myWidth +
		indexWidth];
}


float InputImage::operator()(int indexChannel, int indexHeight, int indexWidth) const
{
	return myData[indexChannel * myWidth * myHeight + indexHeight * myWidth +
		indexWidth];
}


void InputImage::fillImage(float value)
{
	for (int index = 0; index < myHeight * myWidth * myChannel; ++index)
		myData[index] = value;
}


void InputImage::allocate()
{
	freeImage();
	myData = new float(myHeight * myWidth * myChannel);
	memset(myData, 0, myHeight * myWidth * myChannel * sizeof(double));
}


void InputImage::freeImage()
{
	delete myData;
}


InputImage::~InputImage()
{
	freeImage();
}


