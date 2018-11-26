#include "MainWindow.h"
#include <QStyleFactory>
#include <iostream>
namespace interface {


/* The Constructor calls the subfunctions for creation of the sample application */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createGuiControlComponents();

    createStacked();

    createMainLayout();

    createConnections();
}

void MainWindow::createGuiControlComponents() {

    setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::white);
    setPalette(darkPalette);

}


void MainWindow::createMainLayout() {
    centralWidget=new QWidget(this);
    mainLayout=new QHBoxLayout();
    centralWidget->setLayout(mainLayout);
    myPanel = new ControlPanel(this);
    mainLayout->addWidget(myPanel);
    mainLayout->addWidget(myStack);
    setCentralWidget(centralWidget);
}

void MainWindow::createStacked() {
    myWelcomeWindow = new Welcome;
    myDetectionWindow = new Detection;
    myParameterWindow = new Parameters;
    myObjectWindow = new Object;
    myFoodWindow = new Food;
    myPersonWindow = new Person;


    myStack= new QStackedWidget(this);
    myIndexWelcome = myStack->addWidget(myWelcomeWindow);
    myIndexDetection = myStack->addWidget(myDetectionWindow);
    myIndexParameters = myStack->addWidget(myParameterWindow);
    myIndexObjects = myStack->addWidget(myObjectWindow);
    myIndexFoods = myStack->addWidget(myFoodWindow);
    myIndexPersons = myStack->addWidget(myPersonWindow);
}

void MainWindow::createConnections() {

    QObject::connect(myPanel->getButtonDetection(),SIGNAL(pressed()),this,SLOT(toolButtonDetection_on_clicked()));
    QObject::connect(myPanel->getButtonParameters(),SIGNAL(pressed()),this,SLOT(toolButtonParameters_on_clicked()));
    QObject::connect(myPanel->getButtonWelcome(),SIGNAL(pressed()),this,SLOT(toolButtonWelcome_on_clicked()));
    QObject::connect(myPanel->getButtonFoods(),SIGNAL(pressed()),this,SLOT(toolButtonFood_on_clicked()));
    QObject::connect(myPanel->getButtonObjects(),SIGNAL(pressed()),this,SLOT(toolButtonObject_on_clicked()));
    QObject::connect(myPanel->getButtonPersons(),SIGNAL(pressed()),this,SLOT(toolButtonPerson_on_clicked()));
}

void MainWindow::toolButtonDetection_on_clicked()
{
    myStack->setCurrentIndex(myIndexDetection);
    myStack->update();
}

void MainWindow::toolButtonParameters_on_clicked()
{
    myStack->setCurrentIndex(myIndexParameters);
    myStack->update();
}

void MainWindow::toolButtonWelcome_on_clicked()
{
myStack->setCurrentIndex(myIndexWelcome);
myStack->update();
}

void MainWindow::toolButtonFood_on_clicked()
{
    myStack->setCurrentIndex(myIndexFoods);
    myStack->update();
}

void MainWindow::toolButtonObject_on_clicked()
{
    myStack->setCurrentIndex(myIndexObjects);
    myStack->update();
}

void MainWindow::toolButtonPerson_on_clicked()
{
myStack->setCurrentIndex(myIndexPersons);
myStack->update();
}

MainWindow::~MainWindow()
{
    delete myDetectionWindow;
    delete myWelcomeWindow;
    delete myParameterWindow;
    delete myFoodWindow;
    delete myObjectWindow;
    delete myPersonWindow;
    delete myStack;
    delete myPanel;
    delete centralWidget;
    delete mainLayout;
    //delete myMainLayout;
}


}

