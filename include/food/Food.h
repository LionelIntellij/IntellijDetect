#ifndef FOOD_H
#define FOOD_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QToolButton>
#include "ImageFood.h"
#include "StatsFood.h"
#include "TableWidget.h"
#include "SearchWidget.h"


    class Food : public TableWidget {
    Q_OBJECT

    public:
        explicit Food();

        ~Food() final;

    private:
        //Attribute

        ImageFood *myImageWindow;
        StatsFood *myStatisticalWindow;
        SearchWidget *mySearchWindow;

    };
#endif
