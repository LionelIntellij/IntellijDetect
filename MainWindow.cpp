#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QStyleFactory>
//#include <QDebug>
//#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    myUi(new Ui::MainWindow)
{
    myUi->setupUi(this);
    this->setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    createProfil(darkPalette);
    this->setPalette(darkPalette);
    myCircularBarFoods = new QCircularBar();
    myUi->verticalLayoutFoods->addWidget(myCircularBarFoods);
    myCircularBarObjects = new QCircularBar();
    myUi->verticalLayoutObject->addWidget(myCircularBarObjects);
    centerAndResize();
}

void MainWindow::createProfil(QPalette & darkPalette)
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

void MainWindow::centerAndResize() {}

MainWindow::~MainWindow()
{
    delete myUi;
    delete  myCircularBarObjects;
    delete myCircularBarFoods;

}
