#include "actor.h"

Actor::Actor(QString pixmapPath, int x, int y)
{
    pixmap = new QPixmap(pixmapPath);
    pixmapItem = new QGraphicsPixmapItem(*pixmap);
    xPos = x;
    yPos = y;
    pixmapItem->setPos(xPos, yPos);
}

void Actor::setLocation(int x, int y)
{
    xPos = x;
    yPos = y;
    pixmapItem->setPos(xPos, yPos);
}

QPixmap *Actor::getPixmap() const
{
    return pixmap;
}

void Actor::setPixmap(QString value)
{
    QPixmap *pix = new QPixmap(value);
    pixmap = pix;
    pixmapItem->setPixmap(*pix);
}

QGraphicsPixmapItem *Actor::getPixmapItem() const
{
    return pixmapItem;
}

int Actor::getXPos() const
{
    return xPos;
}

void Actor::setXPos(int value)
{
    xPos = value;
}

int Actor::getYPos() const
{
    return yPos;
}

void Actor::setYPos(int value)
{
    yPos = value;
}
