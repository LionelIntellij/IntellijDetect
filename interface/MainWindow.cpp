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
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
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
    myWelcomeWindow = new Welcome();
    myDetectionWindow = new Detection();


    myStack= new QStackedWidget(this);
    myStack->addWidget(myWelcomeWindow);
    myStack->addWidget(myDetectionWindow);


    myCurrentStacked = myStack->currentIndex();
    myNumberStacked = myStack->count();
}

void MainWindow::createConnections() {

    //QObject::connect(myButtonDetection,SIGNAL(pressed()),this,SLOT(slideInNext()));
    //QObject::connect(myButtonFoods,SIGNAL(pressed()),this,SLOT(slideInPrev()));
}


void MainWindow::slideInNext()
{
 int currentStacked = (myCurrentStacked + 1)% myNumberStacked;
  myStack->setCurrentIndex(currentStacked);
  myCurrentStacked = currentStacked;
}


void MainWindow::slideInPrev()
{
 int currentStacked = (myCurrentStacked - 1);
 if (currentStacked < 0)
 {
      myStack->setCurrentIndex(myNumberStacked);
      myCurrentStacked = myNumberStacked;
 }
 else
 {
      myStack->setCurrentIndex(currentStacked);
      myCurrentStacked = currentStacked;
 }
}

void MainWindow::slidePrincipal()
{
myStack->setCurrentIndex(myNumberStacked);
}

MainWindow::~MainWindow()
{
    delete myDetectionWindow;
    delete myWelcomeWindow;
    delete myStack;
    delete myPanel;
    //
    delete centralWidget;
    delete mainLayout;
    //delete myMainLayout;
}


}

