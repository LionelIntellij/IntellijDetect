#ifndef PICTURE_OBJECT_H
#define PICTURE_OBJECT_H

#include <QtWidgets/QtWidgets>
#include <QtWidgets/QGridLayout>
#include "ImageWidget.h"
#include <QtWidgets/QToolButton>


class ImageObject : public ImageWidget{
    Q_OBJECT
    public:
        explicit ImageObject();

        ~ImageObject() final;
        
    private:
      QToolButton * myButtonManualSelect = nullptr; 
    };

#endif
