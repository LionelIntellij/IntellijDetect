#ifndef PICTURE_OBJECT_H
#define PICTURE_OBJECT_H

#include <QWidget>
#include <QGridLayout>
#include "PictureWidget.h"
#include <QToolButton>
namespace object {


class Picture : public picture::PictureWidget{
    Q_OBJECT
    public:
        explicit Picture();

        ~Picture() final;
        
    private:
      QToolButton * myButtonManualSelect = nullptr; 
    };

}
#endif
