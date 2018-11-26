#include "Parameters.h"
#include "UtilsInterface.h"

namespace parameters {

Parameters::Parameters(QWidget *parent):QWidget(parent){
   myTable= new QTabWidget;
   myControlWindow = new Control;
   mySensorWindow = new Sensor;
   myTable->addTab(mySensorWindow ,tr("Sensors"));
   myTable->addTab(myControlWindow , tr("Control"));
   myCurrentIndex = myTable->currentIndex();
   myCountIndex = myTable->count();

   myPreviousButton = new QToolButton;
   myPreviousButton->setMinimumSize(CONTROL_BUTTON_WITDH ,CONTROL_BUTTON_HEIGHT );
   myPreviousButton->setIcon( QIcon(std::string(pathIcons+"left.png").c_str()));
   myPreviousButton->setIconSize(QSize(ICONS_SIZE,ICONS_SIZE));

   myNextButton = new QToolButton;
   myNextButton->setMinimumSize(CONTROL_BUTTON_WITDH ,CONTROL_BUTTON_HEIGHT);
   myNextButton->setIcon( QIcon(std::string(pathIcons+"right.png").c_str()));
   myNextButton->setIconSize(QSize(ICONS_SIZE,ICONS_SIZE));

   myPanelLayout = new QHBoxLayout;
   myPanelLayout->addStretch();
   myPanelLayout->addWidget(myPreviousButton);
   myPanelLayout->addStretch();
   myPanelLayout->addWidget(myNextButton);
   myPanelLayout->addStretch();

   myMainLayout =new QVBoxLayout;
   myMainLayout->addWidget(myTable);
   myMainLayout->addLayout(myPanelLayout);

   setLayout(myMainLayout);
   createConnections();
}

void Parameters::createConnections()
{
    QObject::connect(myNextButton,SIGNAL(pressed()),this,SLOT(toolButtonNext_on_clicked()));
    QObject::connect(myPreviousButton,SIGNAL(pressed()),this,SLOT(toolButtonPrevious_on_clicked()));
}

void Parameters::toolButtonNext_on_clicked()
{
   if (myCurrentIndex == myCountIndex)
   {
      myTable->setCurrentIndex(myCurrentIndex);
   }
   else
   {
      myTable->setCurrentIndex(myCurrentIndex+1);
   }
}

void Parameters::toolButtonPrevious_on_clicked()
{
    if (myCurrentIndex == 0)
    {
       myTable->setCurrentIndex(myCurrentIndex);
    }
    else
    {
       myTable->setCurrentIndex(myCurrentIndex-1);
    }
}

Parameters::~Parameters()
{
  delete mySensorWindow;
  delete myControlWindow;
  delete myTable;
  delete myMainLayout;
  delete myPanelLayout;
  delete myPreviousButton;
  delete myNextButton;
}

}
