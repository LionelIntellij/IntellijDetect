#include "MainWindow.h"
#include <QStyleFactory>
#include <iostream>

namespace interface {


/* The Constructor calls the subfunctions for creation of the sample application */
    MainWindow::MainWindow(QWidget *parent)
            : QMainWindow(parent) {
        createGuiControlComponents();

        createStacked();

        createMainLayout();

        createConnections();
    }

    void MainWindow::createGuiControlComponents() {

        setStyle(QStyleFactory::create("Fusion"));
        QPalette darkPalette;
        darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::WindowText, Qt::white);
        darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
        darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        darkPalette.setColor(QPalette::Text, Qt::white);
        darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ButtonText, Qt::white);
        darkPalette.setColor(QPalette::BrightText, Qt::red);
        darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::HighlightedText, Qt::white);
        setPalette(darkPalette);

    }


    void MainWindow::createMainLayout() {
        centralWidget = new QWidget(this);
        myMainLayout = new QHBoxLayout();
        centralWidget->setLayout(myMainLayout);
        myPanel = new ControlPanel(this);
        myMainLayout->addWidget(myPanel);
        myMainLayout->addWidget(myStack);
        setCentralWidget(centralWidget);
    }

    void MainWindow::createStacked() {
        myWelcomeWindow = new Welcome;
        myDetectionWindow = new detection::Detection;
        myParameterWindow = new parameters::Parameters;
        myObjectWindow = new object::Object;
        myFoodWindow = new food::Food;
        myPersonWindow = new person::Person;


        myStack = new QStackedWidget(this);
        myIndexWelcome = myStack->addWidget(myWelcomeWindow);
        myIndexDetection = myStack->addWidget(myDetectionWindow);
        myIndexParameters = myStack->addWidget(myParameterWindow);
        myIndexObjects = myStack->addWidget(myObjectWindow);
        myIndexFoods = myStack->addWidget(myFoodWindow);
        myIndexPersons = myStack->addWidget(myPersonWindow);
    }

    void MainWindow::createConnections() {

        QObject::connect(myPanel->getButtonDetection(), SIGNAL(pressed()), this,
                         SLOT(toolButton_on_clicked(myIndexDetection)));
        QObject::connect(myPanel->getButtonParameters(), SIGNAL(pressed()), this,
                         SLOT(toolButton_on_clicked(myIndexParameters)));
        QObject::connect(myPanel->getButtonWelcome(), SIGNAL(pressed()), this,
                         SLOT(toolButton_on_clicked(myIndexWelcome)));
        QObject::connect(myPanel->getButtonFoods(), SIGNAL(pressed()), this, SLOT(toolButton_on_clicked(myIndexFoods)));
        QObject::connect(myPanel->getButtonObjects(), SIGNAL(pressed()), this,
                         SLOT(toolButton_on_clicked(myIndexObjects)));
        QObject::connect(myPanel->getButtonPersons(), SIGNAL(pressed()), this,
                         SLOT(toolButton_on_clicked(myIndexPersons)));
    }

    void MainWindow::toolButton_on_clicked(const int index) {
        myStack->setCurrentIndex(index);
        myStack->update();
    }

    MainWindow::~MainWindow() {
        delete myDetectionWindow;
        delete myWelcomeWindow;
        delete myParameterWindow;
        delete myFoodWindow;
        delete myObjectWindow;
        delete myPersonWindow;
        delete myStack;
        delete myPanel;
        delete centralWidget;
        delete myMainLayout;
    }


}

