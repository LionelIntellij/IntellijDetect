#include "CircularBar.h"
#include <QtCore/QtGlobal>
#include <QtGui/QtGui>
#include <QtGui/QPainter>
#include <QtGui/QFont>


CircularBar::CircularBar(QWidget *parent)
    : QWidget(parent)
{
   //m_lcd = new QLCDNumber(this);
}


CircularBar::~CircularBar()
{
    //delete m_lcd;
}



void CircularBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    //int side = qMin(width(), height());
    //painter.setViewport((width() - side) / 2, (height() - side) / 2,side, side);
    //painter.setWindow(-100, -100, 200, 200);

    drawBackground(&painter);
   /* if(circularBarEnabled())
        drawCircularBar(&painter);

    drawTicks(&painter);
    if(coverGlassEnabled())
        drawCoverGlass(&painter);
    drawLabel(&painter);
    drawUnits(&painter);
    drawCrown(&painter);
    if(thresholdEnabled())
        drawThresholdLine(&painter);*/

}


void CircularBar::drawBackground(QPainter *p)
{
    /*
    painter->save();
    QRectF rectangle(-100,-100,200,200);
    painter->setBrush(QColor(225,225,225));
    painter->setPen(QColor(225,225,225));
    painter->drawPie(rectangle, 0, 360*16);
    //painter->setBrush(m_background);
    QColor mColor(110,190,235);
    int startAngle = 0 * 16;
    int spanAngle = 180 * 16;
    double mInnerRadius = 0.6;
    painter->setBrush(mColor);
    painter->setPen(mColor);
    painter->drawPie(rectangle, startAngle, spanAngle);
    //painter->fillRect(rect(), Qt::white);
    //painter->translate(4, 4);
    qreal innerRadius = mInnerRadius*rectangle.width()/2.0;
    painter->setBrush(QColor(53,53,53));
    painter->setPen(QColor(0,0,0, 60));
    painter->drawEllipse(rectangle.center(), innerRadius, innerRadius);
    //painter->drawArc(rectangle,startAngle,spanAngle);
    double progress=0.26;
    QPen pen;
     pen.setWidth(4);
     pen.setColor(mColor);
     painter->setPen(pen);
    painter->drawText(rectangle,Qt::AlignCenter,QString::number(progress*100)+" %");
    painter->restore();
    */
       qreal pi = 0.26;
        qreal pd = pi * 360;
        qreal rd = 360 - pd;
       // QPainter p(this);
        QColor mColor(110,190,235);
        //p.fillRect(rect(),QColor(53,53,53));
        p->translate(10, 10);
        p->setRenderHint(QPainter::Antialiasing);
        QPainterPath path, path2;
        path.moveTo(75, 0);
        path.arcTo(QRectF(0, 0, 150, 150), 90, -pd);
        QPen pen, pen2;
        pen.setCapStyle(Qt::FlatCap);
        pen.setColor(QColor("#30b7e0"));
        pen.setWidth(8);
        p->strokePath(path, pen);
        path2.moveTo(75, 0);
        pen2.setWidth(8);
        pen2.setColor(QColor("#d7d7d7"));
        pen2.setCapStyle(Qt::FlatCap);
        pen2.setDashPattern(QVector<qreal>{0.5, 0.7});
        path2.arcTo(QRectF(0, 0, 150, 150), 90, rd);
        //pen2.setDashOffset(2.2);
        p->strokePath(path2, pen2);
        p->drawText(QRectF(0, 0, 150, 150),Qt::AlignCenter,QString::number(pi*100)+" %");
}


