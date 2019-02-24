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
	void allocate();
	void dealocate();

 private:

	//attribute
	int myHeight;
	int myWidth;
	int myChannel;
	double * myData;


};
