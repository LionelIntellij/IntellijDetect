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


        detection::Detection *myDetectionWindow = nullptr;
        Welcome *myWelcomeWindow = nullptr;
        parameters::Parameters *myParameterWindow = nullptr;
        object::Object *myObjectWindow = nullptr;
        person::Person *myPersonWindow = nullptr;
        food::Food *myFoodWindow = nullptr;

    private:
        QStackedWidget *myStack = nullptr;
        ControlPanel *myPanel = nullptr;
        QHBoxLayout *myMainLayout = nullptr;
        QWidget *centralWidget = nullptr;
        int myIndexParameters = 0;
        int myIndexPersons = 0;
        int myIndexFoods = 0;
        int myIndexObjects = 0;
        int myIndexWelcome = 0;
        int myIndexDetection = 0;

    private slots:

        void toolButton_on_clicked(int index);

    };
}

#endif // MAINWINDOW_H
