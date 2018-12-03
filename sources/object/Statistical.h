#ifndef STATISTICAL_OBJECT
#define STATISTICAL_OBJECT

#include <QWidget>
#include <QGridLayout>


namespace object {

    class Statistical : public QWidget {
    Q_OBJECT
    public:
        explicit Statistical(QWidget *parent = nullptr);

        ~Statistical() final;

    private:
        QGridLayout *myMainLayout = nullptr;


    };

}
#endif
