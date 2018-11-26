#ifndef FOOD_H
#define FOOD_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QToolButton>
#include "Control.h"
#include "Sensor.h"
#include "AddPicture.h"
#include "StatisticalFood.h"

namespace interface {


class Food : public QWidget
{
    Q_OBJECT

public:
    explicit Food(QWidget *parent =0);
    ~Foods();

private:
   //Attribute
  QTabWidget * myTable = nullptr;
  QVBoxLayout *  myMainLayout = nullptr;
  AddPicture * myPictureWindow = nullptr;
  StatisticalFoods * myStatisticalWindow = nullptr;
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
#endif
