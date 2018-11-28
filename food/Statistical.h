#ifndef STATISTICAL_FOOD
#define STATISTICAL_FOOD

#include <QWidget>
#include <QGridLayout>


namespace food {

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