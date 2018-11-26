#include <QWidget>
#include <QGridLayout>


namespace person {

class Statistical : public QWidget
{
    Q_OBJECT
public:
    explicit Statistical(QWidget * parent = 0);
    ~Statistical();

private:
    QGridLayout * myMainLayout = nullptr;


};

}
