#ifndef DETECTION_H
#define DETECTION_H
#include "ui_Detection.h"
#include <QWidget>

class Detection : public QWidget
{
    Q_OBJECT

public:
    explicit Detection(QWidget *parent);
    ~Detection();

private:
    Ui::Detection *myUi;
};

#endif // QDETECTION_H
