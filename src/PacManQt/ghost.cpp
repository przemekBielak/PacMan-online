#include "ghost.h"

/** @file ghost.cpp */

/**
 * @fn Ghost::Ghost()
 * @brief Empty Ghost class constructor.
 * @param void
 * @return void
 */
Ghost::Ghost()
{
    /* */
}

/**
 * @fn Ghost::Ghost(QString pixmapPath, int x, int y)
 * @brief Overloaded Ghost class constructor.
 * @details Updates Ghost graphics, sets x and y positions.
 * @param QString pixmapPath, int x, int y
 * @return void
 */
Ghost::Ghost(QString pixmapPath, int x, int y)
{
    pixmap = new QPixmap(pixmapPath);
    pixmapItem = new QGraphicsPixmapItem(*pixmap);
    xPos = x;
    yPos = y;
    pixmapItem->setPos(xPos, yPos);
}
