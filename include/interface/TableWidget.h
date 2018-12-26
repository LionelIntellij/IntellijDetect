#ifndef TABLE_WIDGET_H
#define TABLE_WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QToolButton>

namespace interface {

    class TableWidget : public QWidget {
    Q_OBJECT

    public:
        explicit TableWidget(QWidget *parent = 0);
 
        ~TableWidget() override;
    private:
        QToolButton *myPreviousButton;
        QToolButton *myNextButton;
        QHBoxLayout *myPanelLayout;

    protected:
        int myCurrentIndex = 0;
        int myCountIndex = 0;
        QTabWidget *myTable;
        QVBoxLayout *myMainLayout;

        //Methods
        void createConnections();

    private slots:

        void toolButtonNext_on_clicked();

        void toolButtonPrevious_on_clicked();


    };
}
#endif // QOJECT

