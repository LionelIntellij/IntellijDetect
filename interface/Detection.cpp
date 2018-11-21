#include "Detection.h"
namespace interface {



Detection::Detection(QWidget *parent) :
    QWidget(parent)
   // myUi(new Ui::Detection)
{
    slideWidget1layout=new QVBoxLayout();
    this->setLayout(slideWidget1layout);
    b11=new QPushButton("Qt");
    slideWidget1layout->addWidget(b11);
    b12=new QPushButton("is cool !");
    slideWidget1layout->addWidget(b12);
    //myUi->setupUi(this);
    //myUi->setCentralWidget()
}

Detection::~Detection()
{
    //delete myUi;
}
}
