#include <utility>

#include "ImageWidget.h"
#include "UtilsInterface.h"
#include "UtilsFilePath.h"
#include <QtGui/QIcon>
#include <QtCore/QSize>
#include <QtCore/QString>
#include <QtWidgets/QFileDialog>
#include <QtCore/QStandardPaths>
#include <QtGui/QImageReader>
#include <QtGui/QImageWriter>
#include <QtWidgets/QMessageBox>

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
    displayImage((utils::pathImage + "baseImage.jpeg").c_str());

    //Stack
    myStack = new QStackedWidget;
    myIndexStackImage = myStack->addWidget(myLabelImage);
    myIndexStackCamera = myStack->addWidget(myViewCamera);

}



void ImageWidget::createTablePhoto() {
    QSize maxSizeButton;
    myButtonOpen = new QToolButton;
    myButtonOpen->setText(tr("Open Photo"));
    myButtonOpen->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonOpen->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
    myButtonOpen->setIcon(QIcon((utils::pathIcons + "open.png").c_str()));
    maxSizeButton = myButtonOpen->minimumSizeHint();

    myButtonSelect = new QToolButton;
    myButtonSelect->setText(tr("Select"));
    myButtonSelect->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonSelect->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
    myButtonSelect->setIcon(QIcon((utils::pathIcons + "detect.png").c_str()));
    setMaximumSizeButton(maxSizeButton, myButtonSelect->minimumSizeHint());

    myButtonSave = new QToolButton;
    myButtonSave->setText(tr("Save"));
    myButtonSave->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonSave->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
    myButtonSave->setIcon(QIcon((utils::pathIcons + "save.png").c_str()));
    setMaximumSizeButton(maxSizeButton, myButtonSave->minimumSizeHint());


    myButtonCancel = new QToolButton;
    myButtonCancel->setText(tr("Cancel"));
    myButtonCancel->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonCancel->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
    myButtonCancel->setIcon(QIcon((utils::pathIcons + "cancel.png").c_str()));
    setMaximumSizeButton(maxSizeButton, myButtonCancel->minimumSizeHint());

    myButtonOpen->setMinimumSize(maxSizeButton);
    myButtonSelect->setMinimumSize(maxSizeButton);
    myButtonSave->setMinimumSize(maxSizeButton);
    myButtonCancel->setMinimumSize(maxSizeButton);

    mySelectLayout = new QGridLayout;
    mySelectLayout->addWidget(myButtonOpen, 0, 0);
    mySelectLayout->addWidget(myButtonSelect, 1, 0);
    mySelectLayout->addWidget(myButtonSave, 2, 0);
    mySelectLayout->addWidget(myButtonCancel, 3, 0);

    myImageWidget = new QWidget;
    myImageWidget->setLayout(mySelectLayout);

    QObject::connect(myButtonOpen, SIGNAL(clicked()), this,
                     SLOT(openImage_on_clicked()));
    QObject::connect(myButtonCancel, SIGNAL(clicked()), this,
                     SLOT(cancelImage_on_clicked()));
}

void ImageWidget::cancelImage_on_clicked() {
    displayImage((utils::pathImage + "baseImage.jpeg").c_str());
}


void ImageWidget::createTableCamera() {
    QSize maxSizeButton;
    myButtonStart = new QToolButton;
    myButtonStart->setText(tr("Start"));
    myButtonStart->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonStart->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
    myButtonStart->setIcon(QIcon((utils::pathIcons + "start.png").c_str()));
    maxSizeButton = myButtonStart->minimumSizeHint();

    myButtonStop = new QToolButton;
    myButtonStop->setText(tr("Stop"));
    myButtonStop->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonStop->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
    myButtonStop->setIcon(QIcon((utils::pathIcons + "stop.png").c_str()));
    setMaximumSizeButton(maxSizeButton, myButtonStop->minimumSizeHint());

    myButtonCapture = new QToolButton;
    myButtonCapture->setText(tr("Capture"));
    myButtonCapture->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    myButtonCapture->setIconSize(QSize(utils::ICONS_SIZE, utils::ICONS_SIZE));
    myButtonCapture->setIcon(QIcon((utils::pathIcons + "camera.png").c_str()));
    setMaximumSizeButton(maxSizeButton, myButtonCapture->minimumSizeHint());

    myButtonStart->setMinimumSize(maxSizeButton);
    myButtonStop->setMinimumSize(maxSizeButton);
    myButtonCapture->setMinimumSize(maxSizeButton);
    myCameraLayout = new QGridLayout;
    myCameraLayout->addWidget(myButtonStart, 0, 0);
    myCameraLayout->addWidget(myButtonStop, 1, 0);
    myCameraLayout->addWidget(myButtonCapture, 2, 0);

    myCameraWidget = new QWidget;
    myCameraWidget->setLayout(myCameraLayout);

}

void ImageWidget::setImage(QImage &newImage) {
    myImage = newImage;
    myLabelImage->setPixmap(QPixmap::fromImage(myImage));
    myLabelImage->adjustSize();
}

static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode) {
    static bool firstDialog = true;

    if (firstDialog) {
        firstDialog = false;
        const QStringList ImagesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(ImagesLocations.isEmpty() ? QDir::currentPath() : ImagesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
                                              ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
            foreach (const QByteArray &mimeTypeName, supportedMimeTypes)mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("jpg");
}

bool ImageWidget::displayImage(const QString &fileName) {
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, tr("Intellij Detect"),
                                 tr("Cannot load %1: %2")
                                         .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
    }

    setImage(newImage);
    return true;
}

void ImageWidget::openImage_on_clicked() {
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);
    while (dialog.exec() == QDialog::Accepted && !displayImage(dialog.selectedFiles().first())) {}
}

void ImageWidget::tabMenu_on_clicked() {
    if (myIndexBarImage == myTable->currentIndex()) {
        displayImage((utils::pathImage + "baseImage.jpeg").c_str());
    }
}

ImageWidget::~ImageWidget() {
    delete myButtonStart;
    delete myButtonStop;
    delete myButtonCapture;

    delete myButtonSelect;
    delete myButtonOpen;
    delete myButtonSave;
    delete myButtonCancel;

    delete myViewCamera;
    delete myLabelImage;

    delete myCameraLayout;
    delete mySelectLayout;

    delete myCameraWidget;
    delete myImageWidget;
    delete myTable;
    delete myStack;
    delete myMainLayout;
}

