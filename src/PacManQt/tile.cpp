#include "tile.h"

Tile::Tile()
{
}

void Tile::setLocation()
{

    pixmapItem->setPos(xPos, yPos);
}

QPixmap *Tile::getPixmap() const
{
    return pixmap;
}

void Tile::setPixmap(QPixmap *value)
{
    pixmap = value;
    pixmapItem = new QGraphicsPixmapItem(*pixmap);
}

QGraphicsPixmapItem *Tile::getPixmapItem() const
{
    return pixmapItem;
}

int Tile::getXPos() const
{
    return xPos;
}

void Tile::setXPos(int value)
{
    xPos = value;
}

int Tile::getYPos() const
{
    return yPos;
}

void Tile::setYPos(int value)
{
    yPos = value;
}
