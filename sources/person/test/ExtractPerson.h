#include <string.h>
#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"


namespace person {


    class ExtractPerson {
    public:
        ExtractPerson(const std::string &ImagePerson);

        ~ExtractPerson();


    private:
        cv::Mat myPersonImage;
    };
}