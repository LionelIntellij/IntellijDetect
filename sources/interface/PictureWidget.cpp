#include "PictureWidget.h"
#include "UtilsInterface.h"
#include <QIcon>
#include <QSize>
#include <QString>
#include <QMessageBox>


    PictureWidget::PictureWidget(QWidget *parent) : QWidget(parent) {
        createTable();
        createStacked();
        myMainLayout= new QGridLayout;
        myMainLayout->addWidget(myStack,0,0,1,5);
        myMainLayout->addWidget(myTable ,0,5,1,2);
        setLayout(myMainLayout);

    }

    void PictureWidget::createStacked()
    {
        myViewCamera = new QCameraViewfinder;
        myLabelPicture = new QLabel;
        myStack = new QStackedWidget;
        myIndexCamera = myStack->addWidget(myViewCamera);
        myIndexPicture = myStack->addWidget(myLabelPicture);
    }

    void PictureWidget::createTable()
    {
        myButtonCapture = new QToolButton;
        myButtonCapture->setText(tr("Photo Capture"));
        myButtonCapture->setMinimumSize(utils::CONTROL_BUTTON_WITDH,utils::CONTROL_BUTTON_HEIGHT);
        myButtonCapture->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        myButtonCapture->setIconSize(QSize(utils::ICONS_SIZE,utils::ICONS_SIZE));
        myButtonCapture->setIcon(QIcon((utils::pathIcons + "camera.png").c_str()));

        myCameraLayout = new QVBoxLayout;
        myCameraLayout->addWidget(myButtonCapture);

        myCameraWidget = new QWidget;
        myCameraWidget->setLayout(myCameraLayout);


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
        mySelectLayout->addWidget(myButtonSave);

        myPictureWidget = new QWidget;
        myPictureWidget->setLayout(mySelectLayout);

        myTable =new QTabWidget;
        myTable->addTab(myCameraWidget,tr("Camera"));
        myTable->addTab(myPictureWidget,tr("Picture"));


    }

/*
    void PictureWidget::setScene(const QString & fileNamePicture)
    {
        if(!fileNamePicture.isEmpty())
        {
            QImage image(fileNamePicture);

            if(image.isNull())
            {
                QMessageBox::information(this,"Image Viewer","Error Displaying image");
                return;
            }
            QGraphicsPixmapItem item(QPixmap::fromImage(image));
            myScene->addItem(&item);

          //  ui->graphicsView->setScene(&scene);
           // ui->graphicsView->show();
        }
    }
    */
    PictureWidget::~PictureWidget()
    {
        delete myButtonSelect;
        delete myButtonCapture;
        delete myButtonSave;

        delete myViewCamera;
        delete myLabelPicture;

        delete myCameraLayout;
        delete mySelectLayout;

        delete myCameraWidget;
        delete myPictureWidget;
        delete myTable;
        delete myStack;
        delete myMainLayout;
    }

