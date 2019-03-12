#ifndef DETECTOR_H
#define  DETECTOR_H
#include "InputImage.h"
#include <opencv2/opencv.hpp>

class Detector
{

public:
	Detector();
	~Detector();

private:
	int batch;
	int total;
	int n, c, h, w;
	int out_n, out_c, out_h, out_w;
	int classes;
	int inputs, outputs;
	int *mask;
	float *biases;
	float *output;
	float *output_gpu;
	
};
#endif
