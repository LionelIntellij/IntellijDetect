
#include "StatsFood.h"

namespace interface {

    StatsFood::StatsFood(QWidget *parent) : QWidget(parent) {

        myMainLayout = new QGridLayout;
        setLayout(myMainLayout);
    }

    StatsFood::~StatsFood() {
        delete myMainLayout;

    }
}
