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
#include "ControlPanel.h"

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

    QHBoxLayout *mainLayout = nullptr;
    QWidget *centralWidget = nullptr;
    Detection *myDetectionWindow = nullptr;
    Welcome * myWelcomeWindow = nullptr;

    int myCurrentStacked= 0;
    int myNumberStacked = 0;

private:
     QStackedWidget *myStack = nullptr;
     ControlPanel * myPanel = nullptr;
     int myIndexParameters = 0;
     int myIndexPersons = 0;
     int myIndexFoods = 0;
     int myIndexObjects = 0;
     int myIndexWelcome = 0;
     int myIndexDetection = 0;

private slots:
     void toolButtonDetection_on_clicked();
     void toolButtonWelcome_on_clicked();



};
}

#endif // MAINWINDOW_H
