#include "Food.h"
//#include "UtilsInterface.h"


    Food::Food() : TableWidget(){

        myImageWindow = new ImageFood;
        myStatisticalWindow = new StatsFood ;
        mySearchWindow = new SearchWidget;
        myTable->addTab(myImageWindow ,tr("Image"));
        myTable->addTab(myStatisticalWindow , tr("Statistical"));
        myTable->addTab(mySearchWindow ,tr("Search"));
        myCountIndex = myTable->count();
        myCurrentIndex = myTable->currentIndex();
    }


    Food::~Food() {
        delete myImageWindow;
        delete myStatisticalWindow;
        delete mySearchWindow;

    }

