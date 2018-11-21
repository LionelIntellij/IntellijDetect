#include "MainWindow.h"
#include <QStyleFactory>

//#include <QDebug>
//#include <QApplication>
namespace interface {


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    //myUi(new Ui::MainWindow)
{
    //myUi->setupUi(this);
    setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    createGui(darkPalette);
    createStackWidget();
    //setCentralWidget(myUi->centralwidget);
    /*QObject::connect(myUi->pushButton_menu,SIGNAL(clicked(bool)),
                      myStack,SLOT(setCurrentWidget(myWelcomeWindow)));*/
/*QObject::connect(myUi->pushButton_detect,SIGNAL(clicked()),
                 myStack,SLOT(setCurrentWidget(myDetection)));*/
}


void MainWindow::createGui(QPalette & darkPalette)
{
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
}

void MainWindow::createStackWidget()
{
myStack = new QStackedWidget(this);
myWelcomeWindow = new WelcomeWindow(this);
myStack->addWidget(myWelcomeWindow);
myDetectionWindow = new Detection(this);
myStack->addWidget(myDetectionWindow);
myCentralWidget=new QWidget(this);
myMainLayout=new QGridLayout();
myCentralWidget->setLayout(myMainLayout);
myMainLayout->addWidget(myStack);
setCentralWidget(myCentralWidget);
}

void MainWindow::switchWindows(QWidget * window)
{
myStack->setCurrentWidget(window);
myStack->update();
}

MainWindow::~MainWindow()
{
    delete myDetectionWindow;
    delete myWelcomeWindow;
    delete myStack;
    //delete myUi;

}
}

