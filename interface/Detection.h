#ifndef DETECTION_H
#define DETECTION_H
//#include "ui_Detection.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

namespace interface {


class Detection : public QWidget
{
    Q_OBJECT

public:
    explicit Detection(QWidget *parent =0);
    ~Detection();

private:
  QVBoxLayout *slideWidget1layout = nullptr;
  QPushButton *b11 = nullptr;
  QPushButton *b12 = nullptr;

    //Ui::Detection *myUi;
};
}
#endif // QDETECTION_H
