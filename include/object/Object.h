#ifndef OBJECT_H
#define OBJECT_H

#include <QToolButton>
#include "PictureObject.h"
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

        PictureObject *myPictureWindow;
        StatsObject *myStatisticalWindow;
        SearchWidget * mySearchWindow;



    };
#endif // QOJECT
