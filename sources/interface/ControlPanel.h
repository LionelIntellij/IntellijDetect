#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QToolButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QIcon>
#include <QPixmap>

namespace interface {

    class ControlPanel : public QWidget {
    Q_OBJECT
    public:
        explicit ControlPanel(QWidget *parent = nullptr);

        ~ControlPanel() override;

        QToolButton *getButtonParameter();

        QToolButton *getButtonPerson();

        QToolButton *getButtonDetection();

        QToolButton *getButtonObject();

        QToolButton *getButtonFood();

        QToolButton *getButtonWelcome();

    private:
        QGroupBox *myBoxPanel = nullptr;
        QVBoxLayout *myControlPanel = nullptr;
        QToolButton *myButtonParameter = nullptr;
        QToolButton *myButtonPerson = nullptr;
        QToolButton *myButtonDetection = nullptr;
        QToolButton *myButtonStatistical = nullptr;
        QToolButton *myButtonObject = nullptr;
        QToolButton *myButtonFood = nullptr;
        QVBoxLayout *myMainBox = nullptr;

        void createGuiComponents();

        void setIconButton();

    };
}
#endif // CONTROLPANEL_H
