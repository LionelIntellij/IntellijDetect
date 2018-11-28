#include "Person.h"
#include "UtilsInterface.h"

namespace person {

Person::Person():TableWidget(this){

    myPictureWindow = new Picture;
    myStatisticalWindow = new Statistical ;
    myTable->addTab(myPictureWindow ,tr("Picture"));
    myTable->addTab(myStatisticalWindow , tr("Statistical"));

}


Person::~Person() {
    delete myPictureWindow;
    delete myStatisticalWindow;

}

}
