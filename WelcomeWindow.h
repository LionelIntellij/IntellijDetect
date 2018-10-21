

#pragma once 
#include <QApplication>
#include <QWidget>
#include <QPushButton>

namespace interface {

class WelcomeWindow : public QWidget // On hérite de QWidget (IMPORTANT)

{

    public:

    WelcomeWindow();

 

    private:

    QPushButton * myButtonParameters; 
    QPushButton * myButtonObject; 
    QPushButton * myButtonSearch; 
    QPushButton * myButtonFood; 
    QPushButton * myButtonSensor; 
   

};

 
}
