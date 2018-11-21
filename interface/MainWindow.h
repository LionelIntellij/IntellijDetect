#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStackedWidget>
#include <QtGui>
#include <QMainWindow>
#include <QPushButton>
#include <QCheckBox>
#include <QListWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include "Detection.h"
#include <QGroupBox>

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
    void createSubSlidingWidgets();
    void createConnections();
    void createStacked();


    QStackedWidget *slidingStacked;
    //QVBoxLayout *mainLayout;
    QHBoxLayout *mainLayout;

    QWidget *centralWidget;
    Detection *myDetectionWindow = nullptr;
    QWidget *slideWidget2;

    int myCurrentStacked= 0;
    int myNumberStacked = 0;

private:
     QGroupBox * myBoxPanel =nullptr;
     QVBoxLayout * myControlPanel = nullptr;
     QPushButton * myButtonParameters = nullptr;
     QPushButton * myButtonSensors = nullptr;
     QPushButton * myButtonDetection = nullptr;
     QPushButton * myButtonObjects = nullptr;
     QPushButton * myButtonFoods = nullptr;

private slots:
    void slideInNext();
    void slideInPrev();
    void slidePrincipal();
};
}

#endif // MAINWINDOW_H
