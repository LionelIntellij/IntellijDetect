#ifndef SENSOR_H
#define SENSOR_H

#include <QWidget>
#include <QVBoxLayout>

namespace interface {

class Sensor : public QWidget
{
    Q_OBJECT
public:
    explicit Sensor(QWidget * parent = 0);
    ~Sensor();

private:
   QVBoxLayout * myMainLayout = nullptr;
};
}
#endif // SENSOR_H
