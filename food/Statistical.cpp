
#include "Statistical.h"

namespace food {

Statistical::Statistical(QWidget * parent):QWidget(parent)
{

    myMainLayout = new QGridLayout;
    setLayout(myMainLayout);
}

Statistical::~Statistical()
{
delete myMainLayout;

}
}
