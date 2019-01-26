#ifndef STATISTICAL_OBJECT
#define STATISTICAL_OBJECT

#include <QWidget>
#include <QGridLayout>



    class StatsObject : public QWidget {
    Q_OBJECT
    public:
        explicit StatsObject(QWidget *parent = 0);

        ~StatsObject() final;

    private:
        QGridLayout *myMainLayout;


    };

#endif
