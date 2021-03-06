#include "MainWindow.h"
#include <QtWidgets/QStyleFactory>

#include <iostream>

/* The Constructor calls the subfunctions for creation of the sample application */
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
  createGuiControlComponents();

  createStacked();

  createMainLayout();

  createConnections();

  centerAndResize();
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

void MainWindow::centerAndResize() {
  // get the dimension available on this screen

  QSize availableSize = myScreen->availableGeometry().size();
  int width = int(availableSize.width() *0.9);
  int height = int(availableSize.height() *0.9);
  qDebug() << "Available dimensions " << width << "x" << height;
  qDebug() << "Computed dimensions " << width << "x" << height;
  QSize newSize(width, height);
  setGeometry(
	  QStyle::alignedRect(
		  Qt::LeftToRight,
		  Qt::AlignCenter,
		  newSize,
		  myScreen->availableGeometry()
	  )
  );
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

  myStatisticsWindow = new Statistics;
  mySettingWindow = new Settings;
  myObjectWindow = new Object;
  myFoodWindow = new Food;
  myPersonWindow = new Person;

  myStack = new QStackedWidget(this);
  myIndexWelcome = myStack->addWidget(myStatisticsWindow);
  myIndexParameter = myStack->addWidget(mySettingWindow);
  myIndexObject = myStack->addWidget(myObjectWindow);
  myIndexFood = myStack->addWidget(myFoodWindow);
  myIndexPerson = myStack->addWidget(myPersonWindow);
}

void MainWindow::createConnections() {

  QObject::connect(myPanel->getButtonParameter(), SIGNAL(pressed()), this,
				   SLOT(toolButtonParameter_on_clicked()));
  QObject::connect(myPanel->getButtonWelcome(), SIGNAL(pressed()), this,
				   SLOT(toolButtonWelcome_on_clicked()));
  QObject::connect(myPanel->getButtonFood(), SIGNAL(pressed()), this,
				   SLOT(toolButtonFood_on_clicked()));
  QObject::connect(myPanel->getButtonObject(), SIGNAL(pressed()), this,
				   SLOT(toolButtonObject_on_clicked()));
  QObject::connect(myPanel->getButtonPerson(), SIGNAL(pressed()), this,
				   SLOT(toolButtonPerson_on_clicked()));
}

void MainWindow::toolButtonParameter_on_clicked() {
  myStack->setCurrentIndex(myIndexParameter);
  myStack->update();
}

void MainWindow::toolButtonWelcome_on_clicked() {
  myStack->setCurrentIndex(myIndexWelcome);
  myStack->update();
}

void MainWindow::toolButtonFood_on_clicked() {
  myStack->setCurrentIndex(myIndexFood);
  myStack->update();
}

void MainWindow::toolButtonObject_on_clicked() {
  myStack->setCurrentIndex(myIndexObject);
  myStack->update();
}

void MainWindow::toolButtonPerson_on_clicked() {
  myStack->setCurrentIndex(myIndexPerson);
  myStack->update();
}

MainWindow::~MainWindow() {
  delete myStatisticsWindow;
  delete mySettingWindow;
  delete myFoodWindow;
  delete myObjectWindow;
  delete myPersonWindow;
  delete myStack;
  delete myPanel;
  delete myMainLayout;
  delete centralWidget;
}



