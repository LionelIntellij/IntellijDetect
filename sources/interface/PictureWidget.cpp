#include "PictureWidget.h"
#include "UtilsInterface.h"
#include <QIcon>
#include <QSize>
#include <QString>
#include <QMessageBox>


namespace interface {
    PictureWidget::PictureWidget(QWidget *parent) : QWidget(parent) {
        createTable();
        myTable =new QTabWidget;
        myTable->addTab(myCamera,tr("Camera"));
        myTable->addTab(myPicture,tr("Picture"));

        myView = new QCameraViewfinder;
        myMainLayout= new QGridLayout;
        myMainLayout->addWidget(myView,0,0,4,6);
        myMainLayout->addWidget(myTable ,0,6,4,1);
        setLayout(myMainLayout);
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

        myCamera = new QWidget;
        myCamera->setLayout(myCameraLayout);


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

        myPicture = new QWidget;
        myPicture->setLayout(mySelectLayout);


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
    PictureWidget::~PictureWidget() {
        delete myMainLayout;
        delete myView;
        delete myCameraLayout;
        delete myPicture;
        delete myTable;
        delete myCamera;
        delete myButtonSelect;
        delete myButtonCapture;
        delete myButtonSave;
    }

}
