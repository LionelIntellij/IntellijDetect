#include <QWidget>
#include <QGridLayout>


namespace food {

class Statistical : public QWidget
{
    Q_OBJECT
public:
    explicit Statistical(QWidget * parent = 0);
    ~StatisticalFood();

private:
    QGridLayout * myMainLayout = nullptr;


};

}
