
#include "StatsObject.h"


    StatsObject::StatsObject(QWidget *parent) : QWidget(parent) {

        myMainLayout = new QGridLayout;
        setLayout(myMainLayout);
    }


    StatsObject::~StatsObject() {
        delete myMainLayout;

    }
