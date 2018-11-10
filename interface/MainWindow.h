#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QCircularBar.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *myUi;
    QCircularBar * myCircularBarFoods;
    QCircularBar * myCircularBarObjects;
    QDetection * myDectection;
    QSensor * mySensor;
    void createProfil(QPalette & darkPalette);
    void centerAndResize();

private slots:

};

#endif // MAINWINDOW_H
