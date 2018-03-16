#include "actor.h"

Actor::Actor(QString pixmapPath, int x, int y)
{
    pixmap = new QPixmap(pixmapPath);
    pixmapItem = new QGraphicsPixmapItem(*pixmap);
    xPos = x;
    yPos = y;
    pixmapItem->setPos(xPos, yPos);
}

void Actor::setLocation()
{
    pixmapItem->setPos(xPos, yPos);
}

QPixmap *Actor::getPixmap() const
{
    return pixmap;
}

void Actor::setPixmap(QPixmap *value)
{
    pixmap = value;
    pixmapItem = new QGraphicsPixmapItem(*pixmap);
}

QGraphicsPixmapItem *Actor::getPixmapItem() const
{
    return pixmapItem;
}

void Actor::setPixmapItem(QGraphicsPixmapItem *value)
{
    pixmapItem = value;
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
