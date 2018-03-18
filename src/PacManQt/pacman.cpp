#include "pacman.h"

Pacman::Pacman()
{
    /* */
}

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
