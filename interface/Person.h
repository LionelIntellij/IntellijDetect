#ifndef PERSON_H
#define PERSON_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QToolButton>
#include "AddPicture.h"
#include "StatisticalPerson.h"

namespace interface {


class Person : public QWidget
{
    Q_OBJECT

public:
    explicit Person(QWidget *parent =0);
    ~Person();

private:
   //Attribute
  QTabWidget * myTable = nullptr;
  QVBoxLayout *  myMainLayout = nullptr;
  AddPicture * myPictureWindow = nullptr;
  StaticticalPerson * myStatisticalWindow = nullptr;
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
#endif // QPERSON
