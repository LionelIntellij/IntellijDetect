
#include "StatisticalObject.h"

namespace interface {

StatisticalObject::StatisticalObject(QWidget * parent):QWidget(parent)
{

    myMainLayout = new QGridLayout;
    setLayout(myMainLayout);
}

StatisticalObject::~StatisticalObject()
{
delete myMainLayout;

}
}
