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

        ~Detection();

        void setTextInfo(const QString &info);

        void setListCompleter();


    private:
        QToolButton *myButtonSearch = nullptr;
        QGridLayout *myMainLayout = nullptr;
        QLineEdit *myTextSearch = nullptr;
        QTextEdit *myTextInfo = nullptr;
        QVBoxLayout *myPanel = nullptr;
        QGraphicsView *myGraphicsView = nullptr;

        void createConnection();

        void createGuiComponents();

    };
}
#endif // QDETECTION_H
