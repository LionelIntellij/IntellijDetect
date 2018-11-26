
#include "StatisticalFood.h"

namespace interface {

StatisticalFood::StatisticalFood(QWidget * parent):QWidget(parent)
{

    myMainLayout = new QGridLayout;
    setLayout(myMainLayout);
}

StatisticalFood::~StatisticalObject()
{
delete myMainLayout;

}
}
