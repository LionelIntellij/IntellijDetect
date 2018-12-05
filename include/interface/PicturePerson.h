#ifndef PICTURE_PERSON_H
#define PICTURE_PERSON_H

#include <QWidget>
#include <QGridLayout>
#include "PictureWidget.h"

namespace interface {

    class PicturePerson : public PictureWidget {
    public:
        explicit PicturePerson();

        ~PicturePerson() final;


    };

}
#endif