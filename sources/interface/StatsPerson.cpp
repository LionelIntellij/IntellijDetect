
#include "interface/StatsPerson.h"

namespace person {

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
