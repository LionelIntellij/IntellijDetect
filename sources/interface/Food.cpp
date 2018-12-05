#include "Food.h"
#include "UtilsInterface.h"

namespace interface {

    Food::Food():TableWidget(){

        myPictureWindow = new PictureFood;
        myStatisticalWindow = new StatsFood ;
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
