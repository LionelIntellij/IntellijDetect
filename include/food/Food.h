#ifndef FOOD_H
#define FOOD_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QToolButton>
#include "PictureFood.h"
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

        PictureFood *myPictureWindow;
        StatsFood *myStatisticalWindow;
        SearchWidget *mySearchWindow;

    };
#endif
