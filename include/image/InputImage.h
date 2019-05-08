#include <QtGui/QImage>
#include <opencv2/opencv.hpp>

class InputImage
{

public:
	//Methods
	InputImage(int height, int width, int channel);
	InputImage();
	~InputImage();
	
	/*inline InputImage &operator=(const InputImage &source)
	{
		return *this;
	}*/
	
	float &operator()(int indexChannel, int indexHeight, int indexWidth);
	float operator()(int indexChannel, int indexHeight, int indexWidth) const;
	void setImage(int height, int width, int channel);
	
	inline int getHeight() const
	{ return myHeight; }
	
	inline int getWidth() const
	{ return myWidth; }
	
	inline int getChannel() const
	{ return myChannel; }
	
	void fillImage(float value);
	void freeImage();

private:
	//methods
	void allocate();
	
	//attribute
	int myHeight;
	int myWidth;
	int myChannel;
	float *myData;
	
};
