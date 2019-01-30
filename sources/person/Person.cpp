#include "Person.h"
#include "UtilsInterface.h"


    Person::Person() : TableWidget() {

        myImageWindow = new ImagePerson;
        myStatisticalWindow = new StatsPerson;
        mySearchWindow = new SearchWidget;
        myTable->addTab(myImageWindow, tr("Image"));
        myTable->addTab(myStatisticalWindow, tr("Statistical"));
        myTable->addTab(mySearchWindow ,tr("Search"));
        myCountIndex = myTable->count();
        myCurrentIndex = myTable->currentIndex();
    }


    Person::~Person() {
        delete myImageWindow;
        delete myStatisticalWindow;
        delete mySearchWindow;

    }

