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
    currTile = xPos/TILE_WIDTH + MAP_TILES_WIDTH * (yPos/TILE_HEIGHT);
}

void Actor::moveLeft()
{
    xPos -= TILE_WIDTH;
}

void Actor::moveRight()
{
    xPos += TILE_WIDTH;
}

void Actor::moveUp()
{
    yPos -= TILE_HEIGHT;
}

void Actor::moveDown()
{
    yPos += TILE_HEIGHT;
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
    return currTile - MAP_TILES_WIDTH;
}

int Actor::getTileIndexDown() const
{
    return currTile + MAP_TILES_WIDTH;
}

int Actor::getLastTile() const
{
    return lastTile;
}

void Actor::setLastTile(int value)
{
    lastTile = value;
}

int Actor::getSpeed() const
{
    return speed;
}

void Actor::setSpeed(int value)
{
    speed = value;
}

int Actor::getDirection() const
{
    return direction;
}

void Actor::setDirection(int value)
{
    direction = value;
}


