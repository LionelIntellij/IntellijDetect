#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QToolButton>
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
