#include "ControlPanel.h"
#include "UtilsFilePath.h"
#include "UtilsInterface.h"
#include <iostream>


ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent) {
    myButtonParameter = new QToolButton;
    myButtonPerson = new QToolButton;
    myButtonObject = new QToolButton;
    myButtonFood = new QToolButton;
    myButtonStatistical = new QToolButton;
    setIconButton();
    QSize maxSizeButton = myButtonParameter->minimumSizeHint();
    setMaximumSizeButton(maxSizeButton, myButtonPerson->minimumSizeHint());
    setMaximumSizeButton(maxSizeButton, myButtonObject->minimumSizeHint());
    setMaximumSizeButton(maxSizeButton, myButtonFood->minimumSizeHint());
    setMaximumSizeButton(maxSizeButton, myButtonStatistical->minimumSizeHint());
    myButtonParameter->setMinimumSize(maxSizeButton);
    myButtonPerson->setMinimumSize(maxSizeButton);
    myButtonObject->setMinimumSize(maxSizeButton);
    myButtonFood->setMinimumSize(maxSizeButton);
    myButtonStatistical->setMinimumSize(maxSizeButton);
    createGuiComponents();
}

void ControlPanel::createGuiComponents() {
    myControlPanel = new QVBoxLayout();
    myBoxPanel = new QGroupBox(tr("Menu"));
    myBoxPanel->setLayout(myControlPanel);
    myControlPanel->addWidget(myButtonParameter);
    myControlPanel->addWidget(myButtonPerson);
    myControlPanel->addWidget(myButtonFood);
    myControlPanel->addWidget(myButtonObject);
    myControlPanel->addWidget(myButtonStatistical);
    myMainBox = new QVBoxLayout;
    myMainBox->addWidget(myBoxPanel);
    setLayout(myMainBox);
}

void ControlPanel::setIconButton() {
    UtilsFilePath path;
    std::string iconsPath;
    path.getPath(UtilsFilePath::ICONS,iconsPath);
    myButtonParameter->setIcon(QIcon((iconsPath + "parameters.png").c_str()));
    myButtonParameter->setIconSize(QSize(ICONS_SIZE, ICONS_SIZE));
    myButtonParameter->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonParameter->setText(tr("Parameters"));

    myButtonFood->setIcon(QIcon((iconsPath + "foods.png").c_str()));
    myButtonFood->setIconSize(QSize(ICONS_SIZE, ICONS_SIZE));
    myButtonFood->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonFood->setText(tr("Foods"));

    myButtonPerson->setIcon(QIcon((iconsPath + "person.png").c_str()));
    myButtonPerson->setIconSize(QSize(ICONS_SIZE, ICONS_SIZE));
    myButtonPerson->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonPerson->setText(tr("Person"));

    myButtonObject->setIcon(QIcon((iconsPath + "objects.png").c_str()));
    myButtonObject->setIconSize(QSize(ICONS_SIZE, ICONS_SIZE));
    myButtonObject->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonObject->setText(tr("Objects"));

    myButtonStatistical->setIcon(QIcon((iconsPath + "statistical.png").c_str()));
    myButtonStatistical->setIconSize(QSize(ICONS_SIZE, ICONS_SIZE));
    myButtonStatistical->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonStatistical->setText(tr("Statistics"));
}

ControlPanel::~ControlPanel() {
    delete myButtonParameter;
    delete myButtonPerson;
    delete myButtonObject;
    delete myButtonFood;
    delete myButtonStatistical;
    delete myControlPanel;
    delete myBoxPanel;
    delete myMainBox;
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

QToolButton *ControlPanel::getButtonObject() {
    return myButtonObject;
}

