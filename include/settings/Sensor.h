#ifndef SENSOR_H
#define SENSOR_H

#include <QWidget>
#include <QVBoxLayout>


class Sensor : public QWidget
{
    Q_OBJECT
public:
    explicit Sensor(QWidget * parent = 0);
    ~Sensor();

private:
   QVBoxLayout * myMainLayout;
};
#endif // SENSOR_H
