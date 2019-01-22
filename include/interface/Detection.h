#ifndef DETECTION_H
#define DETECTION_H

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

namespace interface {


    class Detection : public QWidget {
    Q_OBJECT

    public:
        explicit Detection(QWidget *parent = 0);

        ~Detection() override;

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
}
#endif // QDETECTION_H
