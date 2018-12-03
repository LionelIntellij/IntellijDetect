#ifndef FOOD_H
#define FOOD_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QToolButton>
#include "Picture.h"
#include "Statistical.h"
#include "TableWidget.h"

namespace food {


    class Food : public interface::TableWidget {
    Q_OBJECT

    public:
        explicit Food();

        ~Food() final;

    private:
        //Attribute

        Picture *myPictureWindow = nullptr;
        Statistical *myStatisticalWindow = nullptr;

    };
}
#endif
