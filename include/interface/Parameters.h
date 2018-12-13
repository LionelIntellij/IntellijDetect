#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QToolButton>
#include "Control.h"
#include "Sensor.h"
#include "TableWidget.h"

namespace interface {


    class Parameters : public TableWidget {
    Q_OBJECT

    public:
        explicit Parameters();

        ~Parameters() final;

    private:
        //Attribute
        Sensor *mySensorWindow;
        Control *myControlWindow;
    };
}

#endif // QPARAMETERS
