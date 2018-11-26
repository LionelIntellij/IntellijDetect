#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//QT include
#include <QStackedWidget>
#include <QtGui>
#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QGroupBox>

//class include
#include "Detection.h"
#include "Welcome.h"
#include "Parameters.h"
#include "ControlPanel.h"
#include "Object.h"
#include "Person.h"
#include "Food.h"

namespace interface {


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void createGuiControlComponents();
    void createMainLayout();
    void createConnections();
    void createStacked();


    Detection *myDetectionWindow = nullptr;
    Welcome * myWelcomeWindow = nullptr;
    Parameters * myParameterWindow =nullptr;
    Object * myObjectWindow = nullptr;
    Person * myPersonWindow = nullptr;
    Food * myFoodWindow = nullptr;

private:
     QStackedWidget *myStack = nullptr;
     ControlPanel * myPanel = nullptr;
     QHBoxLayout *mainLayout = nullptr;
     QWidget *centralWidget = nullptr;
     int myIndexParameters = 0;
     int myIndexPersons = 0;
     int myIndexFoods = 0;
     int myIndexObjects = 0;
     int myIndexWelcome = 0;
     int myIndexDetection = 0;

private slots:
     void toolButtonDetection_on_clicked();
     void toolButtonWelcome_on_clicked();
     void toolButtonParameters_on_clicked();
     void toolButtonFood_on_clicked();
     void toolButtonObject_on_clicked();
     void toolButtonPerson_on_clicked();



};
}

#endif // MAINWINDOW_H
