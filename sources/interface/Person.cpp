#include "Person.h"
#include "UtilsInterface.h"

namespace person {

    Person::Person() : TableWidget() {

        myPictureWindow = new Picture;
        myStatisticalWindow = new Statistical;
        myTable->addTab(myPictureWindow, tr("Picture"));
        myTable->addTab(myStatisticalWindow, tr("Statistical"));
        myCountIndex = myTable->count();
        myCurrentIndex = myTable->currentIndex();
    }


    Person::~Person() {
        delete myPictureWindow;
        delete myStatisticalWindow;

    }

}
