#include "PictureWidget.h"


namespace picture {
    PictureWidget::PictureWidget(QWidget *parent) : QWidget(parent) {
        myMainLayout = new QGridLayout;
        setLayout(myMainLayout);
    }

    PictureWidget::~PictureWidget() {
        delete myMainLayout;
    }

}
