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

class PictureWidget : public QWidget {
    Q_OBJECT
    public:
        explicit PictureWidget(QWidget *parent = nullptr);

        //virtual void segmentPicture()=0;

        ~PictureWidget() override;



    private:

        QGridLayout * myMainLayout;
        QGridLayout * mySelectLayout;
        QGridLayout * myCameraLayout;

        QStackedWidget * myStack;
        QCameraViewfinder * myViewCamera;
        QLabel * myLabelPicture;
        int myIndexCamera;
        int myIndexPicture;
        int myIndexBarCamera;
        int myIndexBarPicture;

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
        QToolButton * myButtonCancel;

        //picture
        QString myPathPicture;

        void createTableCamera();
        void createTablePhoto();
        void createStacked();

        void setPathPicture(QString pathPicture);
        const QString & getPathPicture();
        void displayPicture();

    private slots:
        void openPicture_on_clicked();
        void tabMenu_on_clicked();
        //void setScene(const QString & filenamePicture);

    };

#endif
