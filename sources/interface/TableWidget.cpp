#include "TableWidget.h"
#include "UtilsFilePath.h"
#include "UtilsInterface.h"



    TableWidget::TableWidget(QWidget *parent) : QWidget(parent) {
        myTable = new QTabWidget;
        myPreviousButton = new QToolButton;
        UtilsFilePath path;
        std::string pathIcons;
        QSize maxSizeButton;
        path.getPath(UtilsFilePath::ICONS,pathIcons);
        myPreviousButton->setIcon(QIcon(std::string(pathIcons + "left.png").c_str()));
        myPreviousButton->setIconSize(QSize(ICONS_SIZE, ICONS_SIZE));
        maxSizeButton = myPreviousButton->minimumSizeHint();

        myNextButton = new QToolButton;
        myNextButton->setIcon(QIcon(std::string(pathIcons + "right.png").c_str()));
        myNextButton->setIconSize(QSize(ICONS_SIZE, ICONS_SIZE));
        setMaximumSizeButton(maxSizeButton, myNextButton->minimumSizeHint());
        myPreviousButton->setMinimumSize(maxSizeButton);
        myNextButton->setMinimumSize(maxSizeButton);

        myPanelLayout = new QHBoxLayout;
        myPanelLayout->addStretch();
        myPanelLayout->addWidget(myPreviousButton);
        myPanelLayout->addStretch();
        myPanelLayout->addWidget(myNextButton);
        myPanelLayout->addStretch();

        myMainLayout = new QVBoxLayout;
        myMainLayout->addWidget(myTable);
        myMainLayout->addLayout(myPanelLayout);

        setLayout(myMainLayout);
        createConnections();
    }

    void TableWidget::createConnections() {
        QObject::connect(myNextButton, SIGNAL(pressed()), this, SLOT(toolButtonNext_on_clicked()));
        QObject::connect(myPreviousButton, SIGNAL(pressed()), this, SLOT(toolButtonPrevious_on_clicked()));
    }

    void TableWidget::toolButtonNext_on_clicked() {
        if (myCurrentIndex == myCountIndex) {
            myTable->setCurrentIndex(myCurrentIndex);
        } else {
            myCurrentIndex +=1;
            myTable->setCurrentIndex(myCurrentIndex);
        }
    }

    void TableWidget::toolButtonPrevious_on_clicked() {
        if (myCurrentIndex == 0) {
            myTable->setCurrentIndex(myCurrentIndex);
        } else {
            myCurrentIndex-=1;
            myTable->setCurrentIndex(myCurrentIndex);
        }
    }

    TableWidget::~TableWidget() {
        delete myPreviousButton;
        delete myNextButton;
        delete myPanelLayout;
        delete myMainLayout;
        delete myTable;
    }

