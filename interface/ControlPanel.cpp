#include "ControlPanel.h"
#include "UtilsInterface.h"
#include <iostream>
namespace interface {

ControlPanel::ControlPanel(QWidget *parent):QWidget(parent)
{
    myButtonParameters = new QToolButton();

    myButtonParameters->setMinimumSize(PANEL_BUTTON_WITDH,
                                       PANEL_BUTTON_HEIGHT);

    myButtonDetection = new QToolButton();
    myButtonDetection->setMinimumSize(PANEL_BUTTON_WITDH,
                                      PANEL_BUTTON_HEIGHT);
    myButtonPerson = new QToolButton();
    myButtonPerson->setMinimumSize(PANEL_BUTTON_WITDH,
                                    PANEL_BUTTON_HEIGHT);
    myButtonObjects = new QToolButton();
    myButtonObjects->setMinimumSize(PANEL_BUTTON_WITDH,
                                    PANEL_BUTTON_HEIGHT);
    myButtonFoods = new QToolButton();
    myButtonFoods->setMinimumSize(PANEL_BUTTON_WITDH,
                                  PANEL_BUTTON_HEIGHT);
    myButtonStatistical= new QToolButton();
    myButtonStatistical->setMinimumSize(PANEL_BUTTON_WITDH,
                                      PANEL_BUTTON_HEIGHT);
    createGuiComponents();
    setIconButton();
}

void ControlPanel::createGuiComponents()
{
    myControlPanel = new QVBoxLayout();
    myBoxPanel = new QGroupBox(tr("Menu"));
    myBoxPanel->setLayout(myControlPanel);
    myControlPanel->addWidget(myButtonParameters);
    myControlPanel->addWidget(myButtonDetection);
    myControlPanel->addWidget(myButtonPerson);
    myControlPanel->addWidget(myButtonFoods);
    myControlPanel->addWidget(myButtonObjects);
    myControlPanel->addWidget(myButtonStatistical);
    myMainBox = new QVBoxLayout;
    myMainBox->addWidget(myBoxPanel);
    setLayout(myMainBox);
}

void ControlPanel::setIconButton()
{
    //std::cerr<<pathIcons<<std::endl;
    myButtonParameters->setIcon( QIcon(std::string(pathIcons+"parameters.png").c_str()));
    myButtonParameters->setIconSize(QSize(50, 50));
    myButtonParameters->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonParameters->setText("Parameters");

    myButtonFoods->setIcon( QIcon(std::string(pathIcons+"foods.png").c_str()));
    myButtonFoods->setIconSize(QSize(50, 50));
    myButtonFoods->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonFoods->setText("Foods");

    myButtonPerson->setIcon( QIcon(std::string(pathIcons+"person.png").c_str()));
    myButtonPerson->setIconSize(QSize(50, 50));
    myButtonPerson->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonPerson->setText("Person");

    myButtonObjects->setIcon( QIcon(std::string(pathIcons+"objects.png").c_str()));
    myButtonObjects->setIconSize(QSize(50, 50));
    myButtonObjects->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonObjects->setText("Objects");

    myButtonDetection->setIcon( QIcon(std::string(pathIcons+"search.png").c_str()));
    myButtonDetection->setIconSize(QSize(50, 50));
    myButtonDetection->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonDetection->setText("Search");

    myButtonStatistical->setIcon( QIcon(std::string(pathIcons+"statistical.png").c_str()));
    myButtonStatistical->setIconSize(QSize(50, 50));
    myButtonStatistical->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonStatistical->setText("Statistics");

}

 ControlPanel::~ControlPanel(){

         delete myMainBox;
         delete myBoxPanel;
         delete myControlPanel;
         delete myButtonParameters ;
         delete myButtonPerson ;
         delete myButtonDetection ;
         delete myButtonObjects;
         delete myButtonFoods ;
         delete myButtonStatistical ;

 }

 QToolButton * ControlPanel::getButtonParameters()
 {
     return myButtonParameters;
 }

 QToolButton * ControlPanel::getButtonFoods()
 {
     return myButtonFoods;
 }

 QToolButton * ControlPanel::getButtonWelcome()
 {
     return myButtonStatistical;
 }

 QToolButton * ControlPanel::getButtonPersons()
 {
     return myButtonPerson;
 }

 QToolButton * ControlPanel::getButtonDetection()
 {
     return myButtonDetection;
 }

 QToolButton * ControlPanel::getButtonObjects()
 {
     return myButtonObjects;
 }

}
