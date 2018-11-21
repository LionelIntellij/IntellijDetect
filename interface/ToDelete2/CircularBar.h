#ifndef QCIRCULARBAR_H
#define QCIRCULARBAR_H

#include <Qt>
#include <QWidget>
#include <QLCDNumber>
#include <QPropertyAnimation>

namespace interface{
class CircularBar : public QWidget
{
 Q_OBJECT

public:

    CircularBar(QWidget *parent = 0);


        ~CircularBar();



protected:
        void paintEvent(QPaintEvent *event);
        //void resizeEvent(QResizeEvent *event);
        //void changeEvent(QEvent * event);

private:
    void drawBackground(QPainter *painter);

/*
    double m_value;
    double m_maxValue, m_minValue;
    int m_precision;
    QString m_label;
    QString m_units;
    int m_steps;
    int m_barSize;
    int m_startAngle,m_endAngle;
    double m_threshold;
    bool m_autodigits;
    bool m_thresholdEnabled;
    bool m_numericIndicatorEnabled;
    bool m_circularBarEnabled;
    bool m_coverGlassEnabled;
    QColor m_foreground;
    QColor m_background;
    QLCDNumber* m_lcd;*/
};

}
#endif // QCIRCULARBAR_H
