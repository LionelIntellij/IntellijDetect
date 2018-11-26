#include <QWidget>
#include <QGridLayout>


namespace interface {

class StatisticalObject : public QWidget
{
    Q_OBJECT
public:
    explicit StatisticalObject(QWidget * parent = 0);
    ~StatisticalObject();

private:
    QGridLayout * myMainLayout = nullptr;


};

}
