#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>

namespace interface {

class ControlPanel :public QWidget
{
        Q_OBJECT
public:
    explicit ControlPanel(QWidget  * parent = 0);
    ~ControlPanel();

private:
    QGroupBox   * myBoxPanel =nullptr;
    QVBoxLayout * myControlPanel = nullptr;
    QPushButton * myButtonParameters = nullptr;
    QPushButton * myButtonSensors = nullptr;
    QPushButton * myButtonDetection = nullptr;
    QPushButton * myButtonObjects = nullptr;
    QPushButton * myButtonFoods = nullptr;
    QVBoxLayout * myMainBox =nullptr;

    void createGuiComponents();
private slots:


};
}
#endif // CONTROLPANEL_H
