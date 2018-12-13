#ifndef STATISTICAL_PERSON
#define STATISTICAL_PERSON

#include <QWidget>
#include <QGridLayout>


namespace interface {

    class StatsPerson : public QWidget {
    Q_OBJECT
    public:
        explicit StatsPerson(QWidget *parent = 0);

        ~StatsPerson() final;

    private:
        QGridLayout *myMainLayout;

    };
}
#endif
