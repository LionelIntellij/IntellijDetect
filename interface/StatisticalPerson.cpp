
#include "StatisticalPerson.h"

namespace interface {

StatisticalPerson::StatisticalPerson(QWidget * parent):QWidget(parent)
{

    myMainLayout = new QGridLayout;
    setLayout(myMainLayout);
}

StatisticalPerson::~StatisticalPerson()
{
delete myMainLayout;

}
}
