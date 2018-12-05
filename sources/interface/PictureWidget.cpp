#include "PictureWidget.h"
#include "UtilsInterface.h"
#include <QIcon>
#include <QSize>
#include <QString>

namespace interface {
    PictureWidget::PictureWidget(QWidget *parent) : QWidget(parent) {
        createGuiComponents();
        myMainLayout = new QGridLayout;
        myMainLayout->addWidget(myView,0,0,4,6);
        myMainLayout->addWidget(myBoxSelect ,0,6,4,1);
        setLayout(myMainLayout);
    }

    void PictureWidget::createGuiComponents()
    {
        myScene = new QGraphicsScene;
        myView = new QGraphicsView(myScene);

        myButtonCamera = new QToolButton;
        myButtonCamera->setText(tr("Camera"));
        myButtonCamera->setMinimumSize(utils::CONTROL_BUTTON_WITDH,utils::CONTROL_BUTTON_HEIGHT);
        myButtonCamera->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        myButtonCamera->setIconSize(QSize(utils::ICONS_SIZE,utils::ICONS_SIZE));
        myButtonCamera->setIcon(QIcon((utils::pathIcons + "camera.png").c_str()));


        myButtonSelect = new QToolButton;
        myButtonSelect->setText(tr("Select"));
        myButtonSelect->setMinimumSize(utils::CONTROL_BUTTON_WITDH,utils::CONTROL_BUTTON_HEIGHT);
        myButtonSelect->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        myButtonSelect->setIconSize(QSize(utils::ICONS_SIZE,utils::ICONS_SIZE));
        myButtonSelect->setIcon(QIcon((utils::pathIcons + "detect.png").c_str()));

        myButtonSave = new QToolButton;
        myButtonSave->setText(tr("Save"));
        myButtonSave->setMinimumSize(utils::CONTROL_BUTTON_WITDH,utils::CONTROL_BUTTON_HEIGHT);
        myButtonSave->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        myButtonSave->setIconSize(QSize(utils::ICONS_SIZE,utils::ICONS_SIZE));
        myButtonSave->setIcon(QIcon((utils::pathIcons + "save.png").c_str()));

        mySelectLayout = new QVBoxLayout;
        mySelectLayout->addWidget(myButtonSelect);
        mySelectLayout->addWidget(myButtonCamera);
        mySelectLayout->addWidget(myButtonSave);


        myBoxSelect = new QGroupBox(tr("Selection"));
        myBoxSelect->setLayout(mySelectLayout);
    }

    PictureWidget::~PictureWidget() {
        delete myMainLayout;
        delete myView;
        delete myScene;
        delete myBoxSelect;
        delete myButtonSelect;
        delete myButtonCamera;
        delete myButtonSave;
        delete myControlBox;
    }

}
