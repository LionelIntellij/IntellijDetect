#include <QWidget>
#include <QGridLayout>


namespace interface {

class StatisticalFood : public QWidget
{
    Q_OBJECT
public:
    explicit StatisticalFood(QWidget * parent = 0);
    ~StatisticalFood();

private:
    QGridLayout * myMainLayout = nullptr;


};

}
