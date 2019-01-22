#ifndef PICTURE_WIDGET_H
#define PICTURE_WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QToolButton>
#include <QBoxLayout>
#include <QGroupBox>
#include <QTextEdit>
#include <QtMultimedia/QCameraInfo>
#include <QtMultimedia/QMediaMetaData>
#include <QtMultimediaWidgets/QCameraViewfinder>
#include <QtWidgets/QGraphicsPixmapItem>


namespace interface {


    class PictureWidget : public QWidget {
    Q_OBJECT
    public:
        explicit PictureWidget(QWidget *parent = nullptr);

        //virtual void segmentPicture()=0;

        ~PictureWidget() override;

    protected:


    private:
        QCameraViewfinder * myView;
        QGridLayout * myMainLayout;
        QGraphicsScene * myScene;
        QVBoxLayout * myControlBox;
        QToolButton * myButtonSelect;
        QToolButton * myButtonCamera;
        QToolButton * myButtonSave;
        QVBoxLayout * mySelectLayout;
        QGroupBox * myBoxSelect;


        void createGuiComponents();
        //void setScene(const QString & filenamePicture);

    };

}
#endif
