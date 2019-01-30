#include "Object.h"
#include "UtilsInterface.h"


    Object::Object() : TableWidget() {

        myImageWindow = new ImageObject;
        myStatisticalWindow = new StatsObject;
        mySearchWindow = new SearchWidget;
        myTable->addTab(myImageWindow, tr("Image"));
        myTable->addTab(myStatisticalWindow, tr("Statistical"));
        myTable->addTab(mySearchWindow ,tr("Search"));
        myCountIndex = myTable->count();
        myCurrentIndex = myTable->currentIndex();
    }


    Object::~Object() {
        delete myImageWindow;
        delete myStatisticalWindow;
        delete mySearchWindow;

    }
