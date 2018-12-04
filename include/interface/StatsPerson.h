#ifndef STATISTICAL_PERSON
#define STATISTICAL_PERSON

#include <QWidget>
#include <QGridLayout>


namespace person {

    class Statistical : public QWidget {
    Q_OBJECT
    public:
        explicit Statistical(QWidget *parent = 0);

        ~Statistical() final;

    private:
        QGridLayout *myMainLayout = nullptr;

    };
}
#endif