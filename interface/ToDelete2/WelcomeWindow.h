#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H
#include <QWidget>
#include "CircularBar.h"
#include "ui_WelcomeWindow.h"


namespace interface {

class WelcomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent);
    ~WelcomeWindow();

private:
      Ui::WelcomeWindow *myUi =nullptr;
      CircularBar * myCircularBarObjects = nullptr;
      CircularBar * myCircularBarFoods = nullptr;
    //Attributs

};

}
#endif
