#include "Welcome.h"


namespace interface {

Welcome::Welcome(QWidget *parent):QWidget(parent)
{
    myCircularBarFoods = new CircularBar();
    myFoodsLayout = new QVBoxLayout();
    myFoodsLayout->addWidget(myCircularBarFoods);
    myCircularBarObjects = new CircularBar();
    myObjectsLayout = new QVBoxLayout();
    myObjectsLayout->addWidget(myCircularBarObjects);
    myMainLayout = new QHBoxLayout();
    myMainLayout->addLayout(myFoodsLayout);
    myMainLayout->addLayout(myObjectsLayout);
    setLayout(myMainLayout);
}

Welcome::~Welcome(){
    delete myMainLayout;
    delete myCircularBarFoods;
    delete myFoodsLayout;
    delete myCircularBarObjects;
    delete myObjectsLayout;

}
}
