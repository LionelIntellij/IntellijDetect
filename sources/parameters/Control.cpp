#include "Control.h"
namespace parameters {

Control::Control(QWidget * parent):QWidget(parent)
{
  myMainLayout = new QVBoxLayout;
  setLayout(myMainLayout);
}
Control::~Control()
{
 delete myMainLayout;
}

}
