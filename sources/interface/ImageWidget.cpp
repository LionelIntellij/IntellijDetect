#include <utility>

#include "ImageWidget.h"
#include "UtilsInterface.h"
#include <QIcon>
#include <QSize>
#include <QString>
#include <QFileDialog>
#include <QStandardPaths>
#include <QImageReader>

ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent) {
  createTableCamera();
  createTablePhoto();
  myTable = new QTabWidget;
  myIndexBarCamera = myTable->addTab(myCameraWidget, tr("Camera"));
  myIndexBarImage = myTable->addTab(myImageWidget, tr("Image"));

  createStacked();
  myMainLayout = new QGridLayout;
  myMainLayout->addWidget(myStack, 0, 0, 1, 5);
  myMainLayout->addWidget(myTable, 0, 5, 1, 2);
  setLayout(myMainLayout);

  QObject::connect(myTable, SIGNAL(currentChanged(int)), this,
				   SLOT(tabMenu_on_clicked()));
}

void ImageWidget::createStacked() {
  //camera
  myViewCamera = new QCameraViewfinder;

  //Image
  myLabelImage = new QLabel;
  myLabelImage->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  myLabelImage->setScaledContents(true);
  myScrollArea->setBackgroundRole(QPalette::Dark);
  myScrollArea->setWidget(myLabelImage);
  myScrollArea->setVisible(false);

  //Stack
  myStack = new QStackedWidget;
  myIndexStackCamera = myStack->addWidget(myViewCamera);
  myIndexStackImage = myStack->addWidget(myLabelImage);

}

void ImageWidget::createTablePhoto() {
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

  myImageWidget = new QWidget;
  myImageWidget->setLayout(mySelectLayout);

  QObject::connect(myButtonOpen, SIGNAL(clicked()), this,
                   SLOT(openImage_on_clicked()));

}

void ImageWidget::createTableCamera() {
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

void ImageWidget::setImage(QImage &newImage)
{
    myImage = newImage;
    myLabelImage->setPixmap(QPixmap::fromImage(myImage));
    myScrollArea->setVisible(true);
    myLabelImage->adjustSize();
}


static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;

    if (firstDialog) {
        firstDialog = false;
        const QStringList ImagesLocations = QStandardPaths::standardLocations(QStandardPaths::ImagesLocation);
        dialog.setDirectory(ImagesLocations.isEmpty() ? QDir::currentPath() : ImagesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
        ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
    foreach (const QByteArray &mimeTypeName, supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("jpg");
}


bool ImageWidget::displayImage(const QString &fileName)
{
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
    }

    setImage(newImage);
    setWindowFilePath(fileName);

    const QString message = tr("Opened \"%1\", %2x%3, Depth: %4")
        .arg(QDir::toNativeSeparators(fileName)).arg(myImage.width()).arg(myImage.height()).arg(myImage.depth());
    statusBar()->showMessage(message);
    return true;
}


void ImageWidget::openImage_on_clicked() {
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    while (dialog.exec() == QDialog::Accepted && !displayImage(dialog.selectedFiles().first())) {}
}



void ImageWidget::tabMenu_on_clicked() {
  if (myIndexBarCamera == myTable->currentIndex())
  {
    myStack->setCurrentIndex(myIndexStackCamera);
  }
  else
  {
    myStack->setCurrentIndex(myIndexStackImage);
  }
}

ImageWidget::~ImageWidget() {
  delete myButtonStart;
  delete myButtonStop;
  delete myButtonCapture;

  delete myButtonSelect;
  delete myButtonOpen;
  delete myButtonSave;

  delete myViewCamera;
  delete myLabelImage;
  delete myScrollArea;

  delete myCameraLayout;
  delete mySelectLayout;

  delete myCameraWidget;
  delete myImageWidget;
  delete myTable;
  delete myStack;
  delete myMainLayout;
}

