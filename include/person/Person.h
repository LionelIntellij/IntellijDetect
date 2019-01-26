#ifndef PERSON_H
#define PERSON_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QToolButton>
#include "PicturePerson.h"
#include "StatsPerson.h"
#include "TableWidget.h"
#include "SearchWidget.h"

    class Person : public TableWidget {
    Q_OBJECT

    public:
        explicit Person();

        ~Person() final;

    private:
        //Attribute
        PicturePerson *myPictureWindow;
        StatsPerson *myStatisticalWindow;
        SearchWidget * mySearchWindow;


    };
#endif // QPERSON
