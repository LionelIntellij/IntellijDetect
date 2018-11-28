#ifndef PICTURE_FOOD_H
#define PICTURE_FOOD_H

#include <QWidget>
#include <QGridLayout>
#include "PictureWidget.h"

namespace food {


    class Picture : public picture::PictureWidget{
    Q_OBJECT
    public:
        explicit Picture();

        ~Picture() final;
    };

}
#endif
