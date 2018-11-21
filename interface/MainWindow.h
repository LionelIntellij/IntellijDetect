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

    QHBoxLayout *mainLayout;
    QWidget *centralWidget;
    Detection *myDetectionWindow = nullptr;
    Welcome * myWelcomeWindow = nullptr;

    int myCurrentStacked= 0;
    int myNumberStacked = 0;

private:
     QStackedWidget *myStack = nullptr;
     ControlPanel * myPanel = nullptr;

protected slots:
    void slideInNext();
    void slideInPrev();
    void slidePrincipal();
};
}

#endif // MAINWINDOW_H
