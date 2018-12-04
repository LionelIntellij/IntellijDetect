#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QToolButton>
#include "Control.h"
#include "Sensor.h"
#include "TableWidget.h"

namespace parameters {


    class Parameters : public interface::TableWidget {
    Q_OBJECT

    public:
        explicit Parameters();

        ~Parameters() final;

    private:
        //Attribute
        Sensor *mySensorWindow = nullptr;
        Control *myControlWindow = nullptr;
    };
}

#endif // QPARAMETERS
