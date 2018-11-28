#include "ControlPanel.h"
#include "UtilsInterface.h"
#include <iostream>
namespace interface {

ControlPanel::ControlPanel(QWidget *parent):QWidget(parent)
{
    myButtonParameters = new QToolButton;

    myButtonParameters->setMinimumSize(utils::Panel_BUTTON_WITDH,
                                       utils::Panel_BUTTON_HEIGHT);

    myButtonDetection = new QToolButton;
    myButtonDetection->setMinimumSize(utils::Panel_BUTTON_WITDH,
                                      utils::Panel_BUTTON_HEIGHT);
    myButtonPerson = new QToolButton;
    myButtonPerson->setMinimumSize(utils::Panel_BUTTON_WITDH,
                                    utils::Panel_BUTTON_HEIGHT);
    myButtonObjects = new QToolButton;
    myButtonObjects->setMinimumSize(utils::Panel_BUTTON_WITDH,
                                    utils::Panel_BUTTON_HEIGHT);
    myButtonFoods = new QToolButton;
    myButtonFoods->setMinimumSize(utils::Panel_BUTTON_WITDH,
                                  utils::Panel_BUTTON_HEIGHT);
    myButtonStatistical= new QToolButton;
    myButtonStatistical->setMinimumSize(utils::Panel_BUTTON_WITDH,
                                      utils::Panel_BUTTON_HEIGHT);
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
    myButtonParameters->setIconSize(QSize(ICONS_SIZE, ICONS_SIZE));
    myButtonParameters->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonParameters->setText("Parameters");

    myButtonFoods->setIcon( QIcon(std::string(pathIcons+"foods.png").c_str()));
    myButtonFoods->setIconSize(QSize(ICONS_SIZE,ICONS_SIZE));
    myButtonFoods->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonFoods->setText("Foods");

    myButtonPerson->setIcon( QIcon(std::string(pathIcons+"person.png").c_str()));
    myButtonPerson->setIconSize(QSize(ICONS_SIZE,ICONS_SIZE));
    myButtonPerson->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonPerson->setText("Person");

    myButtonObjects->setIcon( QIcon(std::string(pathIcons+"objects.png").c_str()));
    myButtonObjects->setIconSize(QSize(ICONS_SIZE,ICONS_SIZE));
    myButtonObjects->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonObjects->setText("Objects");

    myButtonDetection->setIcon( QIcon(std::string(pathIcons+"search.png").c_str()));
    myButtonDetection->setIconSize(QSize(ICONS_SIZE,ICONS_SIZE));
    myButtonDetection->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonDetection->setText("Search");

    myButtonStatistical->setIcon( QIcon(std::string(pathIcons+"statistical.png").c_str()));
    myButtonStatistical->setIconSize(QSize(ICONS_SIZE,ICONS_SIZE));
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
