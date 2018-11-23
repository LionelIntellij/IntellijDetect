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

class Welcome : public QWidget
    {
        Q_OBJECT

public:
     explicit Welcome(QWidget *parent =0);
     ~ Welcome();

private:
    CircularBar * myCircularBarObjects = nullptr;
    CircularBar * myCircularBarFoods = nullptr;
    QHBoxLayout * myMainLayout = nullptr;
    QVBoxLayout * myObjectsLayout = nullptr;
    QVBoxLayout * myFoodsLayout = nullptr;   
    QVBoxLayout * myPersonsLayout = nullptr;
    QGroupBox * myBoxPersons = nullptr;
    QGroupBox * myBoxFoods = nullptr;
    QGroupBox * myBoxObjects = nullptr;

};
}

#endif // WELCOME_H
