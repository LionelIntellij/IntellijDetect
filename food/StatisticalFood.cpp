
#include "Statistical.h"

namespace food {

Statistical::Statistical(QWidget * parent):QWidget(parent)
{

    myMainLayout = new QGridLayout;
    setLayout(myMainLayout);
}

StatisticalFood::~StatisticalObject()
{
delete myMainLayout;

}
}
