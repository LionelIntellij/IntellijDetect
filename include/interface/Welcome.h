#ifndef WELCOME_H
#define WELCOME_H

//QT include
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QBoxLayout>
#include <QGroupBox>

#include "CircularBar.h"

namespace interface {

    class Welcome : public QWidget {
    Q_OBJECT

    public:
        explicit Welcome(QWidget *parent = 0);

        ~ Welcome() override;

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
}

#endif // WELCOME_H
