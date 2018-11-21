#include "ControlPanel.h"
#include "UtilsInterface.h"
namespace interface {

ControlPanel::ControlPanel(QWidget *parent):QWidget(parent)
{
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
    createGuiComponents();

}

void ControlPanel::createGuiComponents()
{
    myControlPanel = new QVBoxLayout();
    myBoxPanel = new QGroupBox(tr("Menu"));
    myBoxPanel->setLayout(myControlPanel);
    myControlPanel->addWidget(myButtonParameters);
    myControlPanel->addWidget(myButtonSensors);
    myControlPanel->addWidget(myButtonDetection);
    myControlPanel->addWidget(myButtonFoods);
    myControlPanel->addWidget(myButtonObjects);
    myMainBox = new QVBoxLayout;
    myMainBox->addWidget(myBoxPanel);
    setLayout(myMainBox);
}

 ControlPanel::~ControlPanel(){

         delete myMainBox;
         delete myBoxPanel;
         delete myControlPanel;
         delete myButtonParameters ;
         delete myButtonSensors ;
         delete myButtonDetection ;
         delete myButtonObjects;
         delete myButtonFoods ;

 }
}
