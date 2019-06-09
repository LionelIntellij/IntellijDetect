#pragma once
#include <QtWidgets/QtWidgets>
#include <QtWidgets/QGridLayout>



    class StatsPerson : public QWidget {
    Q_OBJECT
    public:
        explicit StatsPerson(QWidget *parent = 0);

        ~StatsPerson() final;

    private:
        QGridLayout *myMainLayout;

    };
