#include <QImage>
#include <opencv2/opencv.hpp>

class Image {

 private:

  QImage *convertQImageToMat( cv::Mat * image);

  cv::Mat *convertMatToQImage( QImage * image);
 public:
  Image(QImage *image)

  ~Image();
};