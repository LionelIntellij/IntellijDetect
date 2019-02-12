
#include "ImagePerson.h"
#include "Image.h"

ImagePerson::ImagePerson() : ImageWidget() {

  QObject::connect(myButtonSelect, SIGNAL(clicked()), this,
				   SLOT(selectPerson_on_clicked()));

}

void ImagePerson::selectPerson_on_clicked() {
  Image image(myImage);

  setImage();

}

ImagePerson::~ImagePerson() = default;
