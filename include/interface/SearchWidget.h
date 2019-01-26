#ifndef SEARCH_WIDGET_H
#define SEARCH_WIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QTextEdit>
#include <QtWidgets/QGraphicsView>
#include <QLineEdit>
#include <QCompleter>
#include <QTextEdit>
#include <QToolButton>
#include <QVBoxLayout>
#include <QGridLayout>



    class SearchWidget : public QWidget {
    Q_OBJECT

    public:
        explicit SearchWidget(QWidget *parent = 0);

        ~SearchWidget() override;

        void setTextInfo(const QString &info);

        void setListCompleter();


    private:
        QToolButton *myButtonSearch;
        QGridLayout *myMainLayout;
        QLineEdit *myTextSearch;
        QTextEdit *myTextInfo;
        QVBoxLayout *myPanel;
        QGraphicsView *myGraphicsView;

        void createConnection();

        void createGuiComponents();

    };
#endif 
