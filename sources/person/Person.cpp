#include "Person.h"
#include "UtilsInterface.h"


    Person::Person() : TableWidget() {

        myPictureWindow = new PicturePerson;
        myStatisticalWindow = new StatsPerson;
        mySearchWindow = new SearchWidget;
        myTable->addTab(myPictureWindow, tr("Picture"));
        myTable->addTab(myStatisticalWindow, tr("Statistical"));
        myTable->addTab(mySearchWindow ,tr("Search"));
        myCountIndex = myTable->count();
        myCurrentIndex = myTable->currentIndex();
    }


    Person::~Person() {
        delete myPictureWindow;
        delete myStatisticalWindow;
        delete mySearchWindow;

    }

