#ifndef YOLO_DETECTOR_H
#define  YOLO_DETECTOR_H
#include "InputImage.h"
#include <opencv2/opencv.hpp>

class Detector
{

public:
	Detector();
	~Detector();

private:
	int channel;
	int width;
	int height;
	int classes;
	std::unique_ptr<float> biases;
	std::unique_ptr<int> mask;
	
	int *mask;
	float *biases;
	float *output;
	float *output_gpu;
	
};
#endif
