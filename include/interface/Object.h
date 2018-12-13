#ifndef OBJECT_H
#define OBJECT_H

#include <QToolButton>
#include "PictureObject.h"
#include "StatsObject.h"
#include "TableWidget.h"

namespace interface {


    class Object : public interface::TableWidget {
    Q_OBJECT

    public:
        explicit Object();

        ~Object() final;

    private:
        //Attribute

        PictureObject *myPictureWindow;
        StatsObject *myStatisticalWindow;


    };
}
#endif // QOJECT
