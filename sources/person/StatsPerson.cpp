
#include "StatsPerson.h"


StatsPerson::StatsPerson(QWidget * parent):QWidget(parent)
{
    myMainLayout = new QGridLayout;
    setLayout(myMainLayout);
}

StatsPerson::~StatsPerson()
{
delete myMainLayout;

}
