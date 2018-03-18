#include "tile.h"

Tile::Tile()
{
    /* */
}

Tile::Tile(QString pixmapPath, int x, int y)
{
    pixmap = new QPixmap(pixmapPath);
    pixmapItem = new QGraphicsPixmapItem(*pixmap);
    xPos = x;
    yPos = y;
    pixmapItem->setPos(xPos, yPos);
}

int Tile::getTileType() const
{
    return tileType;
}

void Tile::setTileType(int value)
{
    tileType = value;
}
