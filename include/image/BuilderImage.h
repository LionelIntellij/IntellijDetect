#include <QImage>
#include <opencv2/opencv.hpp>
#include "InputImage.h"

class BuilderImage {

 public:
  explicit BuilderImage(const QImage &image);
  ~BuilderImage();
  void letterBox(const int height , const int width , InputImage & imageBoxed);

 private:
  //attributes
  InputImage myImage;
  cv::Mat myMatImage;

  //method
  void resizeHorizontal(const int height, const InputImage &imageBase , InputImage & resizedImage);
  void resizeVertical(const int width , InputImage & resizedImage);
  void embedImage( const int deltaVertical, const int deltaHorizontal ,InputImage & boxed );
  
  void resizeImage(const int height, const int width);
  void convertToMat(const QImage &image);
  void iplToImage();
};
