
#include "ImagePerson.h"
#include "Image.h"
#include "Detector.h"
#include <QImage>

ImagePerson::ImagePerson() : ImageWidget() {

  QObject::connect(myButtonSelect, SIGNAL(clicked()), this,
				   SLOT(selectPerson_on_clicked()));

}

void ImagePerson::selectPerson_on_clicked() {
  Image image(&myImage);
  Detector detector(&image);
  setImage((*detector.getSegmentedImage()));
}

ImagePerson::~ImagePerson() = default;
