#include "Detection.h"

Detection::Detection(QWidget *parent) :
    QWidget(parent),
    myUi(new Ui::Detection)
{
    myUi->setupUi(this);
}

Detection::~Detection()
{
    delete myUi;
}
