#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QToolButton>
#include "Control.h"
#include "Sensor.h"

namespace parameters {


class Parameters : public QWidget
{
    Q_OBJECT

public:
    explicit Parameters(QWidget *parent =0);
    ~Parameters();

private:
   //Attribute
  QTabWidget * myTable = nullptr;
  QVBoxLayout *  myMainLayout = nullptr;
  Control * myControlWindow = nullptr;
  Sensor * mySensorWindow = nullptr;
  QHBoxLayout * myPanelLayout = nullptr;
  QToolButton * myPreviousButton = nullptr;
  QToolButton * myNextButton = nullptr;
  int myCurrentIndex = 0;
  int myCountIndex = 0;

  //Methods
  void createConnections();

private slots:
  void toolButtonNext_on_clicked();
  void toolButtonPrevious_on_clicked();

};
}
#endif // QPARAMETERS
