
#include "ImagePerson.h"
#include "BuilderImage.h"
//#include "BuilderNetwork.h"
//#include "Detector.h"
#include <QImage>

ImagePerson::ImagePerson() : ImageWidget() {

  QObject::connect(myButtonSelect, SIGNAL(clicked()), this,
				   SLOT(selectPerson_on_clicked()));

}

void ImagePerson::selectPerson_on_clicked() {
	BuilderImage BuildImage(myImage);
	BuildImage.letterBox();:

}

ImagePerson::~ImagePerson() = default;
