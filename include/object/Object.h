#ifndef OBJECT_H
#define OBJECT_H

#include <QToolButton>
#include "ImageObject.h"
#include "StatsObject.h"
#include "TableWidget.h"
#include "SearchWidget.h"


    class Object : public TableWidget {
    Q_OBJECT

    public:
        explicit Object();

        ~Object() final;

    private:
        //Attribute

        ImageObject *myImageWindow;
        StatsObject *myStatisticalWindow;
        SearchWidget * mySearchWindow;



    };
#endif // QOJECT
