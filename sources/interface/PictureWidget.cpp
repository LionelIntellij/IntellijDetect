#include "PictureWidget.h"
#include "UtilsInterface.h"
#include <QIcon>
#include <QSize>
#include <QString>
#include <QFileDialog>

PictureWidget::PictureWidget(QWidget *parent) : QWidget(parent) {
  createTableCamera();
  createTablePhoto();
  myTable = new QTabWidget;
  myTable->addTab(myCameraWidget, tr("Camera"));
  myTable->addTab(myPictureWidget, tr("Picture"));

  createStacked();
  myMainLayout = new QGridLayout;
  myMainLayout->addWidget(myStack, 0, 0, 1, 5);
  myMainLayout->addWidget(myTable, 0, 5, 1, 2);
  setLayout(myMainLayout);

}

void PictureWidget::createStacked() {
  myViewCamera = new QCameraViewfinder;
  myLabelPicture = new QLabel;
  myStack = new QStackedWidget;
  myIndexCamera = myStack->addWidget(myViewCamera);
  myIndexPicture = myStack->addWidget(myLabelPicture);
}

void PictureWidget::createTablePhoto() {
  myButtonOpen = new QToolButton;
  myButtonOpen->setText(tr("Open Photo"));
  myButtonOpen->setMinimumSize(utils::CONTROL_BUTTON_WITDH, utils::CONTROL_BUTTON_HEIGHT);
  myButtonOpen->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  myButtonOpen->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
  myButtonOpen->setIcon(QIcon((utils::pathIcons + "open.png").c_str()));

  myButtonSelect = new QToolButton;
  myButtonSelect->setText(tr("Select"));
  myButtonSelect->setMinimumSize(utils::CONTROL_BUTTON_WITDH, utils::CONTROL_BUTTON_HEIGHT);
  myButtonSelect->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  myButtonSelect->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
  myButtonSelect->setIcon(QIcon((utils::pathIcons + "detect.png").c_str()));

  myButtonSave = new QToolButton;
  myButtonSave->setText(tr("Save"));
  myButtonSave->setMinimumSize(utils::CONTROL_BUTTON_WITDH, utils::CONTROL_BUTTON_HEIGHT);
  myButtonSave->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  myButtonSave->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
  myButtonSave->setIcon(QIcon((utils::pathIcons + "save.png").c_str()));

  mySelectLayout = new QGridLayout;
  mySelectLayout->addWidget(myButtonOpen, 0, 0);
  mySelectLayout->addWidget(myButtonSelect, 1, 0);
  mySelectLayout->addWidget(myButtonSave, 2, 0);

  myPictureWidget = new QWidget;
  myPictureWidget->setLayout(mySelectLayout);

  QObject::connect(myButtonOpen, SIGNAL(pressed()), this,
                     SLOT(openPicture_on_clicked()));


}

void PictureWidget::createTableCamera() {
  myButtonStart = new QToolButton;
  myButtonStart->setText(tr("Start"));
  myButtonStart->setMinimumSize(utils::CONTROL_BUTTON_WITDH, utils::CONTROL_BUTTON_HEIGHT);
  myButtonStart->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  myButtonStart->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
  myButtonStart->setIcon(QIcon((utils::pathIcons + "start.png").c_str()));

  myButtonStop = new QToolButton;
  myButtonStop->setText(tr("Stop"));
  myButtonStop->setMinimumSize(utils::CONTROL_BUTTON_WITDH, utils::CONTROL_BUTTON_HEIGHT);
  myButtonStop->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  myButtonStop->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
  myButtonStop->setIcon(QIcon((utils::pathIcons + "stop.png").c_str()));

  myButtonCapture = new QToolButton;
  myButtonCapture->setText(tr("Photo Capture"));
  myButtonCapture->setMinimumSize(utils::CONTROL_BUTTON_WITDH, utils::CONTROL_BUTTON_HEIGHT);
  myButtonCapture->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  myButtonCapture->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
  myButtonCapture->setIcon(QIcon((utils::pathIcons + "camera.png").c_str()));

  myCameraLayout = new QGridLayout;
  myCameraLayout->addWidget(myButtonStart, 0, 0);
  myCameraLayout->addWidget(myButtonStop, 1, 0);
  myCameraLayout->addWidget(myButtonCapture, 2, 0);

  myCameraWidget = new QWidget;
  myCameraWidget->setLayout(myCameraLayout);

}
void PictureWidget::setPathPicture(QString pathPicture)
{
   myPathPicture = pathPicture;
}

const QString & PictureWidget::getPathPicture()
{
   return myPathPicture;
}

void PictureWidget::displayPicture()
{
    QPixmap picture(getPathPicture());
    myLabelPicture->setPixmap(picture);
    myLabelPicture->show();
}

void PictureWidget::openPicture_on_clicked() {

    QString pathPicture = QFileDialog::getOpenFileName(this,
        tr("Open Image"), QDir::homePath().toStdString().c_str(), tr("Image Files (*.png *.jpg *.bmp)"));
    if (!pathPicture.isEmpty())
    {
    setPathPicture(pathPicture);
    displayPicture();
    }
}


PictureWidget::~PictureWidget() {
  delete myButtonStart;
  delete myButtonStop;
  delete myButtonCapture;

  delete myButtonSelect;
  delete myButtonOpen;
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

