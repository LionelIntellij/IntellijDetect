#ifndef SEARCH_WIDGET_H
#define SEARCH_WIDGET_H

#include <QtWidgets/QtWidgets>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCompleter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGridLayout>



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
