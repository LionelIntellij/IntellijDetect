#ifndef PERSON_H
#define PERSON_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QToolButton>
#include "Picture.h"
#include "Statistical.h"
#include "TableWidget.h"

namespace person {


    class Person : public interface::TableWidget {
    Q_OBJECT

    public:
        explicit Person();

        ~Person() final;

    private:
        //Attribute
        Picture *myPictureWindow = nullptr;
        Statistical *myStatisticalWindow = nullptr;


    };
}
#endif // QPERSON
