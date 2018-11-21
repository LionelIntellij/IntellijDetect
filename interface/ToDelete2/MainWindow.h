#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include "Sensor.h"

//qt
#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>

#include "Detection.h"
#include "WelcomeWindow.h"
//#include "ui_MainWindow.h"
namespace interface {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //Attributs
    QWidget * myCentralWidget = nullptr;
    QGridLayout *myMainLayout = nullptr;
    //Ui::MainWindow *myUi =nullptr;
    QStackedWidget *myStack = nullptr;
    Detection *myDetectionWindow = nullptr;
    WelcomeWindow * myWelcomeWindow = nullptr;


    //Methods
    void createGui(QPalette & darkPalette);
    void createStackWidget();


public slots:
    void switchWindows(QWidget * window);



/*private slots:
    void on_pushButton_detect_clicked();
*/
};
}

#endif // MAINWINDOW_H
