#include "Food.h"
#include "UtilsInterface.h"

namespace food {

    Food::Food():TableWidget(this){

        myPictureWindow = new Picture;
        myStatisticalWindow = new Statistical ;
        myTable->addTab(myPictureWindow ,tr("Picture"));
        myTable->addTab(myStatisticalWindow , tr("Statistical"));

    }


    Food::~Food() {
        delete myPictureWindow;
        delete myStatisticalWindow;

    }


}
