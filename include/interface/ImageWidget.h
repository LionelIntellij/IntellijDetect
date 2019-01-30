#ifndef Image_WIDGET_H
#define Image_WIDGET_H

//Qt
#include <QWidget>
#include <QGridLayout>
#include <QToolButton>
#include <QBoxLayout>
#include <QTextEdit>
#include <QTableWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QScrollArea>
#include <QImage>
#include <QtMultimedia/QCameraInfo>
#include <QtMultimedia/QMediaMetaData>
#include <QtMultimediaWidgets/QCameraViewfinder>

class ImageWidget : public QWidget {
    Q_OBJECT
    public:
        explicit ImageWidget(QWidget *parent = nullptr);

        //virtual void segmentImage()=0;

        ~ImageWidget() override;



    private:

        QGridLayout * myMainLayout;
        QGridLayout * mySelectLayout;
        QGridLayout * myCameraLayout;

        //stack
        QStackedWidget * myStack;
        QCameraViewfinder * myViewCamera;
        QLabel * myLabelImage;
        int myIndexStackCamera;
        int myIndexStackImage;

        //Table
        QTabWidget * myTable;
        QWidget * myImageWidget;
        QWidget * myCameraWidget;
        int myIndexBarCamera;
        int myIndexBarImage;

        //Buttons Camera
        QToolButton * myButtonCapture;
        QToolButton * myButtonStart;
        QToolButton * myButtonStop;

        //Buttons Photo
        QToolButton * myButtonSelect;
        QToolButton * myButtonOpen;
        QToolButton * myButtonSave;
        QToolButton * myButtonCancel;

        QImage myImage;
        QScrollArea *myScrollArea;

        void createTableCamera();
        void createTablePhoto();

        void createStacked();
        void setImage(QImage &newImage);
        bool displayImage(const QString &fileName);

    private slots:
        void openImage_on_clicked();
        void tabMenu_on_clicked();
        //void setScene(const QString & filenameImage);

    };

#endif
