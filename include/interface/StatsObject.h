#ifndef STATISTICAL_OBJECT
#define STATISTICAL_OBJECT

#include <QWidget>
#include <QGridLayout>


namespace interface {

    class StatsObject : public QWidget {
    Q_OBJECT
    public:
        explicit StatsObject(QWidget *parent);

        ~StatsObject() final;

    private:
        QGridLayout *myMainLayout;


    };

}
#endif
