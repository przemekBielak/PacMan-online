#include "tile.h"

Tile::Tile()
{
}

Tile::Tile(QString pixmapPath, int x, int y)
{
    pixmap = new QPixmap(pixmapPath);
    pixmapItem = new QGraphicsPixmapItem(*pixmap);
    xPos = x;
    yPos = y;
    pixmapItem->setPos(xPos, yPos);
}

void Tile::setLocation()
{
    pixmapItem->setPos(xPos, yPos);
}

QPixmap *Tile::getPixmap() const
{
    return pixmap;
}

void Tile::setPixmap(QString value)
{
    QPixmap *pix = new QPixmap(value);
    pixmap = pix;
    pixmapItem->setPixmap(*pix);
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

