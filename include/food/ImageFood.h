#ifndef PICTURE_FOOD_H
#define PICTURE_FOOD_H

#include <QWidget>
#include <QGridLayout>
#include "ImageWidget.h"



    class ImageFood : public ImageWidget{
    Q_OBJECT
    public:
        explicit ImageFood();

        ~ImageFood() final;
    };

#endif
