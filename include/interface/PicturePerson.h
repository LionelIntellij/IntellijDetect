#ifndef PICTURE_PERSON_H
#define PICTURE_PERSON_H

#include <QWidget>
#include <QGridLayout>
#include "PictureWidget.h"

namespace person {

    class Picture : public picture::PictureWidget {
    public:
        explicit Picture();

        ~Picture() final;


    };

}
#endif