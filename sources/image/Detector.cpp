#include "Detector.h"
#include "UtilsInterface.h"

Detector::Detector(const std::string &networkDetector) {
    	myNet = new Net<float>();

}

Detector::~Detector() {

}
