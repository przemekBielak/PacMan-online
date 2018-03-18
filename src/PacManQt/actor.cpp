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
    updatePos();
    updateCurrTile();
}

void Actor::moveRight()
{
    xPos += TILE_WIDTH;
    updatePos();
    updateCurrTile();
}

void Actor::moveUp()
{
    yPos -= TILE_HEIGHT;
    updatePos();
    updateCurrTile();
}

void Actor::moveDown()
{
    yPos += TILE_HEIGHT;
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
    return currTile - MAP_TILES_WIDTH;
}

int Actor::getTileIndexDown() const
{
    return currTile + MAP_TILES_WIDTH;
}


