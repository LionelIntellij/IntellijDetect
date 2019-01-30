#ifndef PICTURE_OBJECT_H
#define PICTURE_OBJECT_H

#include <QWidget>
#include <QGridLayout>
#include "ImageWidget.h"
#include <QToolButton>


class ImageObject : public ImageWidget{
    Q_OBJECT
    public:
        explicit ImageObject();

        ~ImageObject() final;
        
    private:
      QToolButton * myButtonManualSelect = nullptr; 
    };

#endif
