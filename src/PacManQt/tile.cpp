#include "tile.h"

/** @file tile.cpp */

/**
 * @fn Tile::Tile()
 * @brief Empty Tile class constructor.
 * @param void
 * @return void
 */
Tile::Tile()
{
    /* */
}

/**
 * @fn Tile::Tile(QString pixmapPath, int x, int y)
 * @brief Overloaded Tile class constructor.
 * @details Updates graphics, sets x and y positions.
 * @param QString pixmapPath, int x, int y
 * @return void
 */
Tile::Tile(QString pixmapPath, int x, int y)
{
    pixmap = new QPixmap(pixmapPath);
    pixmapItem = new QGraphicsPixmapItem(*pixmap);
    xPos = x;
    yPos = y;
    pixmapItem->setPos(xPos, yPos);
}

/**
 * @fn int Tile::getTileType() const
 * @brief tileType getter.
 */
int Tile::getTileType() const
{
    return tileType;
}

/**
 * @fn void Tile::setTileType(int value)
 * @brief tileType setter..
 */
void Tile::setTileType(int value)
{
    tileType = value;
}
