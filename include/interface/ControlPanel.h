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
        QGroupBox *myBoxPanel;
        QVBoxLayout *myControlPanel ;
        QToolButton *myButtonParameter ;
        QToolButton *myButtonPerson ;
        QToolButton *myButtonDetection ;
        QToolButton *myButtonStatistical ;
        QToolButton *myButtonObject ;
        QToolButton *myButtonFood ;
        QVBoxLayout *myMainBox ;

        void createGuiComponents();

        void setIconButton();

    };
}
#endif // CONTROLPANEL_H
