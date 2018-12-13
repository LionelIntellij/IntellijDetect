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
        QGridLayout * myMainLayout;
        QGraphicsScene * myScene;
        QGraphicsView * myView;
        QVBoxLayout * myControlBox;
        QToolButton * myButtonSelect;
        QToolButton * myButtonCamera;
        QToolButton * myButtonSave;
        QVBoxLayout * mySelectLayout;
        QGroupBox * myBoxSelect;


        void createGuiComponents();
    };

}
#endif
