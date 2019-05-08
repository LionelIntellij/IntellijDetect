#ifndef PERSON_H
#define PERSON_H

#include <QtWidgets/QtWidgets>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include "ImagePerson.h"
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
        ImagePerson *myImageWindow;
        StatsPerson *myStatisticalWindow;
        SearchWidget * mySearchWindow;


    };
#endif // QPERSON
