
#include "StatsPerson.h"

namespace interface {

StatsPerson::StatsPerson(QWidget * parent):QWidget(parent)
{
    myMainLayout = new QGridLayout;
    setLayout(myMainLayout);
}

StatsPerson::~StatsPerson()
{
delete myMainLayout;

}
}
