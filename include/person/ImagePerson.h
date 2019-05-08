#ifndef PICTURE_PERSON_H
#define PICTURE_PERSON_H

#include <QtWidgets/QtWidgets>
#include <QtWidgets/QGridLayout>
#include "ImageWidget.h"

class ImagePerson : public ImageWidget {
 public:
  explicit ImagePerson();

  ~ImagePerson() final;

 private slots:
  void selectPerson_on_clicked();

};

#endif
