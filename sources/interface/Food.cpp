#include "Food.h"
#include "UtilsInterface.h"

namespace interface {

    Food::Food() : TableWidget(){

        myPictureWindow = new PictureFood;
        myStatisticalWindow = new StatsFood ;
        mySearchWindow = new Detection;
        myTable->addTab(myPictureWindow ,tr("Picture"));
        myTable->addTab(myStatisticalWindow , tr("Statistical"));
        myTable->addTab(mySearchWindow ,tr("Search"));
        myCountIndex = myTable->count();
        myCurrentIndex = myTable->currentIndex();
    }


    Food::~Food() {
        delete myPictureWindow;
        delete myStatisticalWindow;
        delete mySearchWindow;

    }


}
