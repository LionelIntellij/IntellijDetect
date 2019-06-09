#ifndef Image_WIDGET_H
#define Image_WIDGET_H

//Qt
#include <QtWidgets/QtWidgets>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QLabel>
#include <QtGui/QImage>
#include <QtMultimedia/QCameraInfo>
#include <QtMultimedia/QMediaMetaData>
#include <QtMultimediaWidgets/QCameraViewfinder>

class ImageWidget : public QWidget
{
Q_OBJECT
public:
	explicit ImageWidget(QWidget *parent = nullptr);
	
	//virtual void segmentImage()=0;
	
	~ImageWidget() override;

private:
	
	QGridLayout *myMainLayout;
	QGridLayout *mySelectLayout;
	QGridLayout *myCameraLayout;
	
	//stack
	QStackedWidget *myStack;
	QCameraViewfinder *myViewCamera;
	QLabel *myLabelImage;
	int myIndexStackCamera;
	int myIndexStackImage;
	
	//Table
	QTabWidget *myTable;
	QWidget *myImageWidget;
	QWidget *myCameraWidget;
	int myIndexBarCamera;
	int myIndexBarImage;
	
	//Buttons Camera
	QToolButton *myButtonCapture;
	QToolButton *myButtonStart;
	QToolButton *myButtonStop;
	
	//Buttons Photo
	QToolButton *myButtonOpen;
	QToolButton *myButtonSave;
	QToolButton *myButtonCancel;
	
	void createTableCamera();
	void createTablePhoto();
	void createStacked();
	bool displayImage(const QString &fileName);

private slots:
	
	void openImage_on_clicked();
	void tabMenu_on_clicked();
	void cancelImage_on_clicked();

protected:
	//button
	QToolButton *myButtonSelect;
	QImage myImage;
	
	void setImage(QImage &newImage);
	
};

#endif
