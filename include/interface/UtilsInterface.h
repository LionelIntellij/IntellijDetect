#ifndef UTILS_INTERFACE_H
#define UTILS_INTERFACE_H
#include <QIcon>
#include <QSize>
#define ICONS_SIZE 50 //TODO


static void setMaximumSizeButton(QSize &maxSizeButton, QSize sizeButton) {
    if (maxSizeButton.rheight() < sizeButton.rheight())
        maxSizeButton.setHeight(sizeButton.rheight());
    if (maxSizeButton.rwidth() < sizeButton.rwidth())
        maxSizeButton.setWidth(sizeButton.rwidth());
}

#endif