#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//QT include
#include <QtWidgets/QStackedWidget>
#include <QtGui/QtGui>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGroupBox>

//class include
#include "Statistics.h"
#include "Settings.h"
#include "ControlPanel.h"
#include "Object.h"
#include "Person.h"
#include "Food.h"




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

        void centerAndResize();
        Statistics *myStatisticsWindow = nullptr;
        Settings *mySettingWindow = nullptr;
        Object *myObjectWindow = nullptr;
        Person *myPersonWindow = nullptr;
        Food *myFoodWindow = nullptr;

    private:
        QDesktopWidget * myScreen;
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

#endif // MAINWINDOW_H
