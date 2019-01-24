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
#include "Statistics.h"
#include "Parameters.h"
#include "ControlPanel.h"
#include "Object.h"
#include "Person.h"
#include "Food.h"

namespace interface {


    class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);

        ~MainWindow() final;

    protected:
        void createGuiControlComponents();

        void createMainLayout();

        void createConnections();

        void createStacked();

        Statistics *myStatisticsWindow = nullptr;
        Parameters *myParameterWindow = nullptr;
        Object *myObjectWindow = nullptr;
        Person *myPersonWindow = nullptr;
        Food *myFoodWindow = nullptr;

    private:
        QStackedWidget *myStack = nullptr;
        ControlPanel *myPanel = nullptr;
        QHBoxLayout *myMainLayout = nullptr;
        QWidget *centralWidget = nullptr;
        int myIndexParameter = 0;
        int myIndexPerson = 0;
        int myIndexFood = 0;
        int myIndexObject = 0;
        int myIndexWelcome = 0;

    private slots:

        void toolButtonParameter_on_clicked();
        void toolButtonPerson_on_clicked();
        void toolButtonObject_on_clicked();
        void toolButtonWelcome_on_clicked();
        void toolButtonFood_on_clicked();

    };
}

#endif // MAINWINDOW_H
