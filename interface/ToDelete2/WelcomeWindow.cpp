#include "WelcomeWindow.h"


namespace interface{

WelcomeWindow::WelcomeWindow(QWidget *parent)
{
 Q_UNUSED(parent);
 myUi->setupUi(this);
 myCircularBarFoods = new CircularBar();
 myUi->verticalLayout_Foods->addWidget(myCircularBarFoods);
 myCircularBarObjects = new CircularBar();
 myUi->verticalLayout_Object->addWidget(myCircularBarObjects);
}


WelcomeWindow::~WelcomeWindow ()
{
delete myCircularBarObjects;
delete myCircularBarFoods;
delete myUi;
}
}
