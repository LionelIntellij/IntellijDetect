#ifndef PICTURE_FOOD_H
#define PICTURE_FOOD_H

#include <QWidget>
#include <QGridLayout>
#include "PictureWidget.h"

namespace interface {


    class PictureFood : public PictureWidget{
    Q_OBJECT
    public:
        explicit PictureFood();

        ~PictureFood() final;
    };

}
#endif
