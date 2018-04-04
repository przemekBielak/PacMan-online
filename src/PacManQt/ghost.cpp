#include "ghost.h"

/**
 * @fn Ghost()
 * @brief Empty Ghost class constructor.
 * @param void
 * @return void
 */
Ghost::Ghost()
{
    /* */
}

/**
 * @fn Ghost()
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
