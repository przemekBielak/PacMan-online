#include "actor.h"

Actor::Actor()
{
    /* */
}

Actor::Actor(QString pixmapPath, int x, int y)
{
    pixmap = new QPixmap(pixmapPath);
    pixmapItem = new QGraphicsPixmapItem(*pixmap);
    xPos = x;
    yPos = y;
    pixmapItem->setPos(xPos, yPos);
}

int Actor::getCurrTile() const
{
    return currTile;
}

void Actor::updateCurrTile(void)
{
    currTile = xPos/20 + 27 * (yPos/20);
}

void Actor::moveLeft()
{
    xPos -= 20;
    updatePos();
    updateCurrTile();
}

void Actor::moveRight()
{
    xPos += 20;
    updatePos();
    updateCurrTile();
}

void Actor::moveUp()
{
    yPos -= 20;
    updatePos();
    updateCurrTile();
}

void Actor::moveDown()
{
    yPos += 20;
    updatePos();
    updateCurrTile();
}

int Actor::getTileIndexLeft() const
{
    return currTile - 1;
}

int Actor::getTileIndexRight() const
{
    return currTile + 1;
}

int Actor::getTileIndexUp() const
{
    return currTile - 27;
}

int Actor::getTileIndexDown() const
{
    return currTile + 27;
}


