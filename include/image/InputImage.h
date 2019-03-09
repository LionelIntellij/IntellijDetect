#include <QImage>
#include <opencv2/opencv.hpp>

class InputImage
{

public:
	//Methods
	InputImage(int height, int width, int channel );
	~InputImage();
	double operator();
	double& operator();
	inline const int getHeight(){ return myHeight; }
	inline const int getWidth(){ return myWidth; }
	void fillImage(float value);
	void freeImage();

private:
	void allocate();


	//attribute
	int myHeight;
	int myWidth;
	int myChannel;
	double * myData;


};
