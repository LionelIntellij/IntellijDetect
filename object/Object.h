#ifndef OBJECT_H
#define OBJECT_H

#include <QToolButton>
#include "Picture.h"
#include "Statistical.h"
#include "TableWidget.h"

namespace object {


class Object : public interface::TableWidget
{
    Q_OBJECT

public:
    explicit Object();
    ~Object() final;

private:
   //Attribute

  Picture * myPictureWindow = nullptr;
  Statistical * myStatisticalWindow = nullptr;

private slots:


};
}
#endif // QOJECT
