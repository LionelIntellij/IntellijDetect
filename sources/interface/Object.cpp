#include "Object.h"
#include "UtilsInterface.h"

namespace interface {

    Object::Object() : TableWidget() {

        myPictureWindow = new PictureObject;
        myStatisticalWindow = new StatsObject;
        mySearchWindow = new Detection;
        myTable->addTab(myPictureWindow, tr("Picture"));
        myTable->addTab(myStatisticalWindow, tr("Statistical"));
        myTable->addTab(mySearchWindow ,tr("Search"));
        myCountIndex = myTable->count();
        myCurrentIndex = myTable->currentIndex();
    }


    Object::~Object() {
        delete myPictureWindow;
        delete myStatisticalWindow;
        delete mySearchWindow;

    }
}
