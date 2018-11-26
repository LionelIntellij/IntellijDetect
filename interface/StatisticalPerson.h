#include <QWidget>
#include <QGridLayout>


namespace interface {

class StatisticalPerson : public QWidget
{
    Q_OBJECT
public:
    explicit StatisticalPerson(QWidget * parent = 0);
    ~StatisticalPerson();

private:
    QGridLayout * myMainLayout = nullptr;


};

}
