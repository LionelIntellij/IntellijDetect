#ifndef TABLE_WIDGET_H
#define TABLE_WIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QToolButton>

namespace interface {

class TableWidget : public QWidget
{
    Q_OBJECT

public:
  explicit TableWidget(QWidget * parent);
    ~TableWidget();
private:
    QTabWidget * myTable = nullptr;
    QVBoxLayout *  myMainLayout = nullptr;
    QHBoxLayout * myPanelLayout = nullptr;
    QToolButton * myPreviousButton = nullptr;
    QToolButton * myNextButton = nullptr;
    int myCurrentIndex = 0;
    int myCountIndex = 0;

    //Methods
    void createConnections();

  private slots:
    void toolButtonNext_on_clicked();
    void toolButtonPrevious_on_clicked();


};
}
#endif // QOJECT

