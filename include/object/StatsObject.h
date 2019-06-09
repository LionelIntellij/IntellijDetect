#ifndef STATISTICAL_OBJECT
#define STATISTICAL_OBJECT

#include <QtWidgets/QtWidgets>
#include <QtWidgets/QGridLayout>



    class StatsObject : public QWidget {
    Q_OBJECT
    public:
        explicit StatsObject(QWidget *parent = 0);

        ~StatsObject() final;

    private:
        QGridLayout *myMainLayout;


    };

#endif
