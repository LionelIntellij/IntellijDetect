#ifndef CONTROL_H
#define CONTROL_H

#include <QWidget>
#include <QVBoxLayout>

namespace interface {

class Control : public QWidget
{
  Q_OBJECT

public:
    explicit Control(QWidget *parent = 0);
    ~Control();
private:
    QVBoxLayout * myMainLayout;
};
}
#endif // CONTROL_H
