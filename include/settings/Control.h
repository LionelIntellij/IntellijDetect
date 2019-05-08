#ifndef CONTROL_H
#define CONTROL_H

#include <QtWidgets/QtWidgets>
#include <QtWidgets/QVBoxLayout>


class Control : public QWidget
{
  Q_OBJECT

public:
    explicit Control(QWidget *parent = 0);
    ~Control();
private:
    QVBoxLayout * myMainLayout;
};
#endif // CONTROL_H
