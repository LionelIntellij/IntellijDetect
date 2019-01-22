#ifndef PICTURE_WIDGET_H
#define PICTURE_WIDGET_H

//Qt
#include <QWidget>
#include <QGridLayout>
#include <QToolButton>
#include <QBoxLayout>
#include <QTextEdit>
#include <QTableWidget>
#include <QtMultimedia/QCameraInfo>
#include <QtMultimedia/QMediaMetaData>
#include <QtMultimediaWidgets/QCameraViewfinder>


namespace interface {


    class PictureWidget : public QWidget {
    Q_OBJECT
    public:
        explicit PictureWidget(QWidget *parent = nullptr);

        //virtual void segmentPicture()=0;

        ~PictureWidget() override;

    protected:


    private:

        QGridLayout * myMainLayout;
        QVBoxLayout * mySelectLayout;
        QVBoxLayout * myCameraLayout;

        QCameraViewfinder * myView;
        QTabWidget * myTable;
        QWidget * myPicture;
        QWidget * myCamera;

        //Buttons
        QToolButton * myButtonSelect;
        QToolButton * myButtonCapture;
        QToolButton * myButtonSave;

        void createTable();
        //void setScene(const QString & filenamePicture);

    };

}
#endif
