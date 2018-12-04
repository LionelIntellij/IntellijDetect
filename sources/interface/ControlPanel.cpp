#include "ControlPanel.h"
#include "UtilsInterface.h"
#include <iostream>

namespace interface {

    ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent) {
        myButtonParameter = new QToolButton;

        myButtonParameter->setMinimumSize(utils::PANEL_BUTTON_WITDH,
                                           utils::PANEL_BUTTON_HEIGHT);

        myButtonDetection = new QToolButton;
        myButtonDetection->setMinimumSize(utils::PANEL_BUTTON_WITDH,
                                          utils::PANEL_BUTTON_HEIGHT);
        myButtonPerson = new QToolButton;
        myButtonPerson->setMinimumSize(utils::PANEL_BUTTON_WITDH,
                                       utils::PANEL_BUTTON_HEIGHT);
        myButtonObject = new QToolButton;
        myButtonObject->setMinimumSize(utils::PANEL_BUTTON_WITDH,
                                        utils::PANEL_BUTTON_HEIGHT);
        myButtonFood = new QToolButton;
        myButtonFood->setMinimumSize(utils::PANEL_BUTTON_WITDH,
                                      utils::PANEL_BUTTON_HEIGHT);
        myButtonStatistical = new QToolButton;
        myButtonStatistical->setMinimumSize(utils::PANEL_BUTTON_WITDH,
                                            utils::PANEL_BUTTON_HEIGHT);
        createGuiComponents();
        setIconButton();
    }

    void ControlPanel::createGuiComponents() {
        myControlPanel = new QVBoxLayout();
        myBoxPanel = new QGroupBox(tr("Menu"));
        myBoxPanel->setLayout(myControlPanel);
        myControlPanel->addWidget(myButtonParameter);
        myControlPanel->addWidget(myButtonDetection);
        myControlPanel->addWidget(myButtonPerson);
        myControlPanel->addWidget(myButtonFood);
        myControlPanel->addWidget(myButtonObject);
        myControlPanel->addWidget(myButtonStatistical);
        myMainBox = new QVBoxLayout;
        myMainBox->addWidget(myBoxPanel);
        setLayout(myMainBox);
    }

    void ControlPanel::setIconButton() {
        //std::cerr<<pathIcons<<std::endl;
        myButtonParameter->setIcon(QIcon((utils::pathIcons + "parameters.png").c_str()));
        myButtonParameter->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
        myButtonParameter->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        myButtonParameter->setText("Parameters");

        myButtonFood->setIcon(QIcon((utils::pathIcons + "foods.png").c_str()));
        myButtonFood->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
        myButtonFood->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        myButtonFood->setText("Foods");

        myButtonPerson->setIcon(QIcon((utils::pathIcons + "person.png").c_str()));
        myButtonPerson->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
        myButtonPerson->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        myButtonPerson->setText("Person");

        myButtonObject->setIcon(QIcon((utils::pathIcons + "objects.png").c_str()));
        myButtonObject->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
        myButtonObject->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        myButtonObject->setText("Objects");

        myButtonDetection->setIcon(QIcon((utils::pathIcons + "search.png").c_str()));
        myButtonDetection->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
        myButtonDetection->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        myButtonDetection->setText("Search");

        myButtonStatistical->setIcon(QIcon((utils::pathIcons + "statistical.png").c_str()));
        myButtonStatistical->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
        myButtonStatistical->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        myButtonStatistical->setText("Statistics");

    }

    ControlPanel::~ControlPanel() {

        delete myMainBox;
        delete myBoxPanel;
        delete myControlPanel;
        delete myButtonParameter;
        delete myButtonPerson;
        delete myButtonDetection;
        delete myButtonObject;
        delete myButtonFood;
        delete myButtonStatistical;

    }

    QToolButton *ControlPanel::getButtonParameter() {
        return myButtonParameter;
    }

    QToolButton *ControlPanel::getButtonFood() {
        return myButtonFood;
    }

    QToolButton *ControlPanel::getButtonWelcome() {
        return myButtonStatistical;
    }

    QToolButton *ControlPanel::getButtonPerson() {
        return myButtonPerson;
    }

    QToolButton *ControlPanel::getButtonDetection() {
        return myButtonDetection;
    }

    QToolButton *ControlPanel::getButtonObject() {
        return myButtonObject;
    }

}
