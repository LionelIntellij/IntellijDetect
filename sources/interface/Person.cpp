#include "Person.h"
#include "UtilsInterface.h"

namespace interface {

    Person::Person() : TableWidget() {

        myPictureWindow = new PicturePerson;
        myStatisticalWindow = new StatsPerson;
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
