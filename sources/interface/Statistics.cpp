#include "Statistics.h"



    Statistics::Statistics(QWidget *parent) : QWidget(parent) {
        myCircularBarFoods = new CircularBar;
        myFoodsLayout = new QVBoxLayout;
        myFoodsLayout->addWidget(myCircularBarFoods);
        myBoxFoods = new QGroupBox(tr("Foods"));
        myBoxFoods->setLayout(myFoodsLayout);

        myCircularBarObjects = new CircularBar;

        myObjectsLayout = new QVBoxLayout;
        myObjectsLayout->addWidget(myCircularBarObjects);

        myBoxObjects = new QGroupBox(tr("Objects"));
        myBoxObjects->setLayout(myObjectsLayout);

        myPersonsLayout = new QVBoxLayout;
        myBoxPersons = new QGroupBox(tr("Persons"));

        myBoxPersons->setLayout(myPersonsLayout);

        myMainLayout = new QHBoxLayout;
        myMainLayout->addWidget(myBoxFoods);
        myMainLayout->addWidget(myBoxObjects);
        myMainLayout->addWidget(myBoxPersons);

        setLayout(myMainLayout);
    }

    Statistics::~Statistics() {
        delete myCircularBarObjects;
        delete myCircularBarFoods;

        delete myMainLayout;
        delete myPersonsLayout;
        delete myFoodsLayout;
        delete myObjectsLayout;

        delete myBoxPersons;
        delete myBoxFoods;
        delete myBoxObjects;

    }
