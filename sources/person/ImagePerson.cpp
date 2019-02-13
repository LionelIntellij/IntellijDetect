
#include "ImagePerson.h"
#include "Image.h"
#include <QImage>
#include "Detector.h"

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
