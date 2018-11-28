#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H
#include <QToolButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QIcon>
#include <QPixmap>

namespace interface {

class ControlPanel :public QWidget
{
        Q_OBJECT
public:
    explicit ControlPanel(QWidget  * parent = 0);
    ~ControlPanel() override;

    QToolButton * getButtonParameters();
    QToolButton * getButtonPersons();
    QToolButton * getButtonDetection();
    QToolButton * getButtonObjects();
    QToolButton * getButtonFoods();
    QToolButton * getButtonWelcome();

private:
    QGroupBox   * myBoxPanel =nullptr;
    QVBoxLayout * myControlPanel = nullptr;
    QToolButton * myButtonParameters = nullptr;
    QToolButton * myButtonPerson = nullptr;
    QToolButton * myButtonDetection = nullptr;
    QToolButton * myButtonStatistical = nullptr;
    QToolButton * myButtonObjects = nullptr;
    QToolButton * myButtonFoods = nullptr;
    QVBoxLayout * myMainBox =nullptr;

    void createGuiComponents();
    void setIconButton();

};
}
#endif // CONTROLPANEL_H
