/**********************************************************************************/
/*                                                                                */
/* Project Open-GUI                                                               */
/*                                                                                */
/* Copyright (c) by Paolo Sereno <paolo.sereno@open-gui.eu> All rights reserved.  */
/*                                                                                */
/* This library is free software; you can redistribute it and/or                  */
/* modify it under the terms of the GNU Lesser General Public                     */
/* License as published by the Free Software Foundation; either                   */
/* version 3.0 of the License, or (at your option) any later version.             */
/* This library is distributed in the hope that it will be useful,                */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of                 */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU               */
/* Lesser General Public License for more details.                                */
/* You should have received a copy of the GNU Lesser General Public               */
/* License along with this library.                                               */
/*                                                                                */
/**********************************************************************************/

#ifndef QCIRCULARBAR_H
#define QCIRCULARBAR_H

#include <Qt>
#include <QWidget>
#include <QLCDNumber>
#include <QPropertyAnimation>

class QColor;

/*!
  \brief QCircularBar is a custom widget plugin to display values. It consists of a scale and a needle
  to show the value within a lower and an upper limit.
  The angle associated to the limits in the widget scale can be modified by appropriate slots.
  A threshold limit can be enabled to handle alarm signals coherent with the input value.
  Once installed in Qt designer, right click on the widget and select QCircularBar...,
  the associated help dialog will be displayed to show more details about the widget.

*/
class QCircularBar : public QWidget
{
 Q_OBJECT

public:

    QCircularBar(QWidget *parent = 0);


        ~QCircularBar();



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


#endif // QCIRCULARBAR_H
