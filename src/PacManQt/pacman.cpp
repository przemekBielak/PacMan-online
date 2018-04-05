#include "pacman.h"

/** @file pacman.cpp */

/**
 * @fn Pacman::Pacman()
 * @brief Empty actor class constructor.
 * @param void
 * @return void
 */
Pacman::Pacman()
{
    /* */
}

/**
 * @fn Pacman::Pacman(QString pixmapPath, int x, int y)
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
 * @fn int Pacman::getNumOfLifes() const
 * @brief numOfLifes getter.
 */
int Pacman::getNumOfLifes() const
{
    return numOfLifes;
}

/**
 * @fn void Pacman::setNumOfLifes(int value)
 * @brief numOfLifes setter.
 */
void Pacman::setNumOfLifes(int value)
{
    numOfLifes = value;
}

/**
 * @fn int Pacman::getPoints() const
 * @brief points getter.
 */
int Pacman::getPoints() const
{
    return points;
}

/**
 * @fn void Pacman::setPoints(int value)
 * @brief points setter.
 */
void Pacman::setPoints(int value)
{
    points = value;
}
