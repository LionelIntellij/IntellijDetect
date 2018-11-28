#include "Object.h"
#include "UtilsInterface.h"

namespace object {

    Object::Object() : TableWidget() {

        myPictureWindow = new Picture;
        myStatisticalWindow = new Statistical;
        myTable->addTab(myPictureWindow, tr("Picture"));
        myTable->addTab(myStatisticalWindow, tr("Statistical"));
        myCountIndex = myTable->count();
        myCurrentIndex = myTable->currentIndex();
    }


    Object::~Object() {
        delete myPictureWindow;
        delete myStatisticalWindow;

    }
}
