#include "Parameters.h"
#include "UtilsInterface.h"

namespace interface {

    Parameters::Parameters() : TableWidget() {

        myControlWindow = new Control;
        mySensorWindow = new Sensor;
        myTable->addTab(mySensorWindow, tr("Sensors"));
        myTable->addTab(myControlWindow, tr("Control"));
        myCurrentIndex = myTable->currentIndex();
        myCountIndex = myTable->count();
    }

    Parameters::~Parameters() {
        delete mySensorWindow;
        delete myControlWindow;
    }
}
