#include "MainWindow.h"
#include "UtilsInterface.h"
#include <QStyleFactory>

namespace interface {


/* The Constructor calls the subfunctions for creation of the sample application */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createGuiControlComponents();
    createSubSlidingWidgets();
    createStacked();
    createMainLayout();
    createConnections();
}

MainWindow::~MainWindow() {
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
    myButtonParameters = new QPushButton(tr("Parameters"));
    myButtonParameters->setMinimumSize(PANEL_BUTTON_WITDH,
                                       PANEL_BUTTON_HEIGHT);
    myButtonSensors = new QPushButton(tr("Sensors"));
    myButtonSensors->setMinimumSize(PANEL_BUTTON_WITDH,
                                    PANEL_BUTTON_HEIGHT);
    myButtonDetection = new QPushButton(tr("Detect"));
    myButtonDetection->setMinimumSize(PANEL_BUTTON_WITDH,
                                      PANEL_BUTTON_HEIGHT);
    myButtonObjects = new QPushButton(tr("Objects"));
    myButtonObjects->setMinimumSize(PANEL_BUTTON_WITDH,
                                    PANEL_BUTTON_HEIGHT);
    myButtonFoods = new QPushButton(tr("Foods"));
    myButtonFoods->setMinimumSize(PANEL_BUTTON_WITDH,
                                  PANEL_BUTTON_HEIGHT);
}


void MainWindow::createMainLayout() {
    centralWidget=new QWidget(this);
    mainLayout=new QHBoxLayout();
    //myBoxPanel = new QGroupBox(tr("&Push Buttons"));
    centralWidget->setLayout(mainLayout);
    myControlPanel = new QVBoxLayout();
    //myBoxPanel->setLayout(myControlPanel);
    mainLayout->addLayout(myControlPanel);
    mainLayout->addWidget(slidingStacked);

    myControlPanel->addWidget(myButtonParameters);
    myControlPanel->addWidget(myButtonSensors);
    myControlPanel->addWidget(myButtonDetection);
    myControlPanel->addWidget(myButtonFoods);
    myControlPanel->addWidget(myButtonObjects);

    this->setCentralWidget(centralWidget);
}

void MainWindow::createSubSlidingWidgets() {
    myDetectionWindow = new Detection();
    slideWidget2 = new QWidget();

    QVBoxLayout *slideWidget2layout=new QVBoxLayout();
    slideWidget2->setLayout(slideWidget2layout);
    QPushButton *b21=new QPushButton("Cool");
    slideWidget2layout->addWidget(b21);
    QPushButton *b22=new QPushButton("is Qt !");
    slideWidget2layout->addWidget(b22);
}

void MainWindow::createStacked() {
    slidingStacked= new QStackedWidget(this);
    slidingStacked->addWidget(myDetectionWindow);
    slidingStacked->addWidget(slideWidget2);


    myCurrentStacked = slidingStacked->currentIndex();
    myNumberStacked = slidingStacked->count();
}

void MainWindow::createConnections() {

    QObject::connect(myButtonDetection,SIGNAL(pressed()),this,SLOT(slideInNext()));
    QObject::connect(myButtonFoods,SIGNAL(pressed()),this,SLOT(slideInPrev()));
}


void MainWindow::slideInNext()
{
 int currentStacked = (myCurrentStacked + 1)% myNumberStacked;
  slidingStacked->setCurrentIndex(currentStacked);
  myCurrentStacked = currentStacked;
}


void MainWindow::slideInPrev()
{
 int currentStacked = (myCurrentStacked - 1);
 if (currentStacked < 0)
 {
      slidingStacked->setCurrentIndex(myNumberStacked);
      myCurrentStacked = myNumberStacked;
 }
 else
 {
      slidingStacked->setCurrentIndex(currentStacked);
      myCurrentStacked = currentStacked;
 }
}

void MainWindow::slidePrincipal()
{
slidingStacked->setCurrentIndex(myNumberStacked);
}

}

