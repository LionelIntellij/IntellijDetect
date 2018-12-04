#include "Sensor.h"

namespace parameters {

Sensor::Sensor(QWidget * parent):QWidget(parent)
{
    myMainLayout = new QVBoxLayout;
    setLayout(myMainLayout);
}

Sensor::~Sensor()
{
 delete myMainLayout;
}
}
