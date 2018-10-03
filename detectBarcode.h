#include "zbar.h"
#include "opencv2/opencv.hpp"
#include <string>
#include<vector>
#include "opencv2/highgui/highgui_c.h"
typedef struct
{
    std::string type;
    std::string data;
    std::vector <cv::Point> location;
} DecodedObject;


class DetectBarcode {

public:
    explicit DetectBarcode(cv::Mat & image);

    void getDecodedObjects(std::vector<DecodedObject> &decodedObjects);

private:

    cv::Mat m_image;
    unsigned int m_height;
    unsigned int m_width;

};