#ifndef STATISTICAL_FOOD
#define STATISTICAL_FOOD

#include <QWidget>
#include <QGridLayout>



    class StatsFood : public QWidget {
    Q_OBJECT
    public:
        explicit StatsFood(QWidget *parent = 0);

        ~StatsFood() final;

    private:
        QGridLayout *myMainLayout;


    };


#endif
