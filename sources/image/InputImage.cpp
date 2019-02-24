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

void InputImage::allocate()
{
	dealocate();
	data = new double(myHeight*myWidth*myChannel);
	memset(data,0,myHeight*myWidth*myChannel*sizeof(double));
}

void InputImage::dealocate()
{
	if(myData)
		delete myData;
}

InputImage::~InputImage()
{
	deallocate()	;
}


