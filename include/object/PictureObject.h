#ifndef PICTURE_OBJECT_H
#define PICTURE_OBJECT_H

#include <QWidget>
#include <QGridLayout>
#include "PictureWidget.h"
#include <QToolButton>


class PictureObject : public PictureWidget{
    Q_OBJECT
    public:
        explicit PictureObject();

        ~PictureObject() final;
        
    private:
      QToolButton * myButtonManualSelect = nullptr; 
    };

#endif
