#ifndef PICTURE_WIDGET_H
#define PICTURE_WIDGET_H

//Qt
#include <QWidget>
#include <QGridLayout>
#include <QToolButton>
#include <QBoxLayout>
#include <QTextEdit>
#include <QTableWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QtMultimedia/QCameraInfo>
#include <QtMultimedia/QMediaMetaData>
#include <QtMultimediaWidgets/QCameraViewfinder>
#include "DialogFileSystem.h"
#include "../../sources/interface/DialogFileSystem.h"

class PictureWidget : public QWidget {
    Q_OBJECT
    public:
        explicit PictureWidget(QWidget *parent = nullptr);

        //virtual void segmentPicture()=0;

        ~PictureWidget() override;

    protected:


    private:

        QGridLayout * myMainLayout;
        QGridLayout * mySelectLayout;
        QGridLayout * myCameraLayout;

        QStackedWidget * myStack;
        QCameraViewfinder * myViewCamera;
        QLabel * myLabelPicture;
        int myIndexCamera;
        int myIndexPicture;

        QTabWidget * myTable;
        QWidget * myPictureWidget;
        QWidget * myCameraWidget;

        //Buttons Camera
        QToolButton * myButtonCapture;
        QToolButton * myButtonStart;
        QToolButton * myButtonStop;

        //Buttons Photo
        QToolButton * myButtonSelect;
        QToolButton * myButtonOpen;
        QToolButton * myButtonSave;

        DialogFileSystem * myDialogWindow;

        void createTableCamera();
        void createTablePhoto();
        void createStacked();
        void openPicture_on_clicked();

        //void setScene(const QString & filenamePicture);

    };

#endif
