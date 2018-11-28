#include <QWidget>
#include <QGridLayout>


namespace object {

    class Statistical : public QWidget {
    Q_OBJECT
    public:
        explicit Statistical(QWidget *parent = nullptr);

        ~Statistical();

    private:
        QGridLayout *myMainLayout = nullptr;


    };

}
