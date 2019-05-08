#ifndef STATICTICS_H
#define STATICTICS_H

//QT include
#include <QtWidgets/QtWidgets>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QGroupBox>

#include "CircularBar.h"


    class Statistics : public QWidget {
    Q_OBJECT

    public:
        explicit Statistics(QWidget *parent = 0);

        ~ Statistics() override;

    private:
        CircularBar *myCircularBarObjects;
        CircularBar *myCircularBarFoods;

        QHBoxLayout *myMainLayout;
        QVBoxLayout *myObjectsLayout;
        QVBoxLayout *myFoodsLayout;
        QVBoxLayout *myPersonsLayout;

        QGroupBox *myBoxPersons;
        QGroupBox *myBoxFoods;
        QGroupBox *myBoxObjects;

    };

#endif // WELCOME_H
