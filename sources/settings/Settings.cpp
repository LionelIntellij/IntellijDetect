#include "Settings.h"
#include "UtilsInterface.h"


    Settings::Settings() : TableWidget() {

        myControlWindow = new Control;
        mySensorWindow = new Sensor;
        myTable->addTab(mySensorWindow, tr("Sensors"));
        myTable->addTab(myControlWindow, tr("Control"));
        myCurrentIndex = myTable->currentIndex();
        myCountIndex = myTable->count();
    }

    Settings::~Settings() {
        delete mySensorWindow;
        delete myControlWindow;
    }
