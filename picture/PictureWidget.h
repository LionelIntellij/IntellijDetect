#ifndef PICTURE_WIDGET_H
#define PICTURE_WIDGET_H

#include <QWidget>
#include <QGridLayout>

namespace picture {


    class PictureWidget : public QWidget {
    Q_OBJECT
    public:
        explicit PictureWidget(QWidget *parent = nullptr);

        ~PictureWidget() override;

    private:
        QGridLayout *myMainLayout = nullptr;

    };

}
#endif
