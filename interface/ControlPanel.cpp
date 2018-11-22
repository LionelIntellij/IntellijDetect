#include "ControlPanel.h"
#include "UtilsInterface.h"
namespace interface {

ControlPanel::ControlPanel(QWidget *parent):QWidget(parent)
{
    myButtonParameters = new QToolButton();

    myButtonParameters->setMinimumSize(PANEL_BUTTON_WITDH,
                                       PANEL_BUTTON_HEIGHT);
    myButtonSensors = new QToolButton();
    myButtonSensors->setMinimumSize(PANEL_BUTTON_WITDH,
                                    PANEL_BUTTON_HEIGHT);
    myButtonDetection = new QToolButton();
    myButtonDetection->setMinimumSize(PANEL_BUTTON_WITDH,
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
    myControlPanel->addWidget(myButtonSensors);
    myControlPanel->addWidget(myButtonDetection);
    myControlPanel->addWidget(myButtonFoods);
    myControlPanel->addWidget(myButtonObjects);
    myControlPanel->addWidget(myButtonStatistical);
    myMainBox = new QVBoxLayout;
    myMainBox->addWidget(myBoxPanel);
    setLayout(myMainBox);
}

void ControlPanel::setIconButton()
{
    myButtonParameters->setIcon( QIcon("/home/lionel/Projets/IntellijDetect/icons/parameters.png"));
    myButtonParameters->setIconSize(QSize(50, 50));
    myButtonParameters->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonParameters->setText("Parameters");

    myButtonFoods->setIcon( QIcon("/home/lionel/Projets/IntellijDetect/icons/foods.png"));
    myButtonFoods->setIconSize(QSize(50, 50));
    myButtonFoods->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonFoods->setText("Foods");

    myButtonSensors->setIcon( QIcon("/home/lionel/Projets/IntellijDetect/icons/sensors.png"));
    myButtonSensors->setIconSize(QSize(50, 50));
    myButtonSensors->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonSensors->setText("Sensors");

    myButtonObjects->setIcon( QIcon("/home/lionel/Projets/IntellijDetect/icons/objects.png"));
    myButtonObjects->setIconSize(QSize(50, 50));
    myButtonObjects->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonObjects->setText("Objects");

    myButtonDetection->setIcon( QIcon("/home/lionel/Projets/IntellijDetect/icons/search.png"));
    myButtonDetection->setIconSize(QSize(50, 50));
    myButtonDetection->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonDetection->setText("Search");

    myButtonStatistical->setIcon( QIcon("/home/lionel/Projets/IntellijDetect/icons/statistical.png"));
    myButtonStatistical->setIconSize(QSize(50, 50));
    myButtonStatistical->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonStatistical->setText("statistics");

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
