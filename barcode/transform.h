#include <vector>

namespace barcode{
    void getCenterPoint(const std::vector< cv::RotatedRect > & vecRotRect , std::vector<cv::Point> & center);

}