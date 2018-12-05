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

namespace interface {


    class PictureWidget : public QWidget {
    Q_OBJECT
    public:
        explicit PictureWidget(QWidget *parent = nullptr);

        ~PictureWidget() override;

    private:
        QGridLayout * myMainLayout = nullptr;
        QGraphicsScene * myScene = nullptr;
        QGraphicsView * myView = nullptr;
        QVBoxLayout * myControlBox = nullptr;
        QToolButton * myButtonSelect = nullptr;
        QToolButton * myButtonCamera = nullptr;
        QToolButton * myButtonSave = nullptr;
        QVBoxLayout * mySelectLayout = nullptr;
        QGroupBox * myBoxSelect = nullptr;


        void createGuiComponents();
    };

}
#endif
