#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QtWidgets/QToolButton>
#include <QtWidgets/QtWidgets>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGroupBox>
#include <QtGui/QIcon>
#include <QtGui/QPixmap>


    class ControlPanel : public QWidget {
    Q_OBJECT
    public:
        explicit ControlPanel(QWidget *parent = nullptr);

        ~ControlPanel() override;

        QToolButton *getButtonParameter();

        QToolButton *getButtonPerson();

        QToolButton *getButtonObject();

        QToolButton *getButtonFood();

        QToolButton *getButtonWelcome();

    private:
        QGroupBox *myBoxPanel;
        QVBoxLayout *myControlPanel ;
        QToolButton *myButtonParameter ;
        QToolButton *myButtonPerson ;
        QToolButton *myButtonStatistical ;
        QToolButton *myButtonObject ;
        QToolButton *myButtonFood ;
        QVBoxLayout *myMainBox ;

        void createGuiComponents();

        void setIconButton();

    };
#endif // CONTROLPANEL_H
