#include <QIcon>
#include <QSize>


static void setMaximumSizeButton(QSize &maxSizeButton, QSize sizeButton) {
    if (maxSizeButton.rheight() < sizeButton.rheight())
        maxSizeButton.setHeight(sizeButton.rheight());
    if (maxSizeButton.rwidth() < sizeButton.rwidth())
        maxSizeButton.setWidth(sizeButton.rwidth());
}
