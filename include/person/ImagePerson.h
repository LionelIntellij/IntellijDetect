#ifndef PICTURE_PERSON_H
#define PICTURE_PERSON_H

#include <QWidget>
#include <QGridLayout>
#include "ImageWidget.h"

class ImagePerson : public ImageWidget {
 public:
  explicit ImagePerson();

  ~ImagePerson() final;

 private slots:
  void selectPerson_on_clicked();

};

#endif
