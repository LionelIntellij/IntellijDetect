#include "Food.h"
#include "UtilsInterface.h"

namespace food {

    Food::Food():TableWidget(){

        myPictureWindow = new Picture;
        myStatisticalWindow = new Statistical ;
        myTable->addTab(myPictureWindow ,tr("Picture"));
        myTable->addTab(myStatisticalWindow , tr("Statistical"));
        myCountIndex = myTable->count();
        myCurrentIndex = myTable->currentIndex();
    }


    Food::~Food() {
        delete myPictureWindow;
        delete myStatisticalWindow;

    }


}
