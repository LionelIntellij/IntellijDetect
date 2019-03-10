#include "InputImage.h"
#include <opencv2/opencv.hpp>
#include <caffe/caffe.hpp>


class Detector{

 public:
 Detector();
 ~Detector();

 private:
  std::unique_ptr<caffe::Net<float>> myNet;

};
ls
