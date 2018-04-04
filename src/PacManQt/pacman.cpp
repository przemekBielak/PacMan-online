#include "pacman.h"


/**
 * @fn Pacman()
 * @brief Empty actor class constructor.
 * @param void
 * @return void
 */
Pacman::Pacman()
{
    /* */
}

/**
 * @fn Pacman()
 * @brief Overloaded actor class constructor.
 * @details Updates Pacman graphics, sets x and y positions,
 * sets initial number of lives and points.
 * @param QString pixmapPath, int x, int y
 * @return void
 */
Pacman::Pacman(QString pixmapPath, int x, int y)
{
    pixmap = new QPixmap(pixmapPath);
    pixmapItem = new QGraphicsPixmapItem(*pixmap);
    xPos = x;
    yPos = y;
    pixmapItem->setPos(xPos, yPos);
    numOfLifes = 3;
    points = 0;
}

/**
 * @fn int getNumOfLifes() const
 * @brief numOfLifes getter.
 */
int Pacman::getNumOfLifes() const
{
    return numOfLifes;
}

void Pacman::setNumOfLifes(int value)
{
    numOfLifes = value;
}

int Pacman::getPoints() const
{
    return points;
}

void Pacman::setPoints(int value)
{
    points = value;
}
