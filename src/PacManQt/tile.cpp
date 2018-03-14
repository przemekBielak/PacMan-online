#include "tile.h"

Tile::Tile()
{
    pixmap = new QPixmap(":/Images/rosekane_4.png");
    pixmapItem = new QGraphicsPixmapItem(*pixmap);
}

Tile::setLocation(int x, int y)
{
    xPos = x;
    yPos = y;
    pixmapItem->setPos(xPos, yPos);
}
