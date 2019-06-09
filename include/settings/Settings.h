#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtWidgets/QtWidgets>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include "Control.h"
#include "Sensor.h"
#include "TableWidget.h"



    class Settings : public TableWidget {
    Q_OBJECT

    public:
        explicit Settings();

        ~Settings() final;

    private:
        //Attribute
        Sensor *mySensorWindow;
        Control *myControlWindow;
    };

#endif // QPARAMETERS
