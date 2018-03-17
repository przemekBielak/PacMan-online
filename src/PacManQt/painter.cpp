#include "painter.h"

Painter::Painter()
{
    /* */
}

Painter::Painter(QString pixmapPath, int x, int y)
{
    pixmap = new QPixmap(pixmapPath);
    pixmapItem = new QGraphicsPixmapItem(*pixmap);
    xPos = x;
    yPos = y;
    pixmapItem->setPos(xPos, yPos);
}

void Painter::setLocation(int x, int y)
{
    xPos = x;
    yPos = y;
    pixmapItem->setPos(xPos, yPos);
}

QPixmap *Painter::getPixmap() const
{
    return pixmap;
}

void Painter::setPixmap(QString value)
{
    QPixmap *pix = new QPixmap(value);
    pixmap = pix;
    pixmapItem->setPixmap(*pix);
}

QGraphicsPixmapItem *Painter::getPixmapItem() const
{
    return pixmapItem;
}

int Painter::getXPos() const
{
    return xPos;
}

void Painter::setXPos(int value)
{
    xPos = value;
}

int Painter::getYPos() const
{
    return yPos;
}

void Painter::setYPos(int value)
{
    yPos = value;
}
