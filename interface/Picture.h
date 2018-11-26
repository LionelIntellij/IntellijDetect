#ifndef PICTURE_H
#define PICTURE_H
#include <QWidget>
#include <QGridLayout>

namespace interface {


class AddPicture : public QWidget
{
    Q_OBJECT
public:
 explicit AddPicture(Qwidget * parent = 0);
  ~AddPicture();

private:
    QGridLayout * myMainLayout = nullptr;

};

}
#endif
