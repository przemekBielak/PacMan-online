#include "actor.h"

/** @file actor.cpp */

/**
 * @fn Actor::Actor()
 * @brief Empty actor class constructor.
 * @param void
 * @return void
 */
Actor::Actor()
{
    /* */
}

/**
 * @fn Actor::Actor(QString pixmapPath, int x, int y)
 * @brief Overloaded actor class constructor.
 * @details Updates Actors graphics and sets x and y positions.
 * @param QString pixmapPath, int x, int y
 * @return void
 */
Actor::Actor(QString pixmapPath, int x, int y)
{
    pixmap = new QPixmap(pixmapPath);
    pixmapItem = new QGraphicsPixmapItem(*pixmap);
    xPos = x;
    yPos = y;
    pixmapItem->setPos(xPos, yPos);
}

/**
 * @fn int Actor::getCurrTile() const
 * @brief currTile getter.
 * @param void
 * @return int currTile
 */
int Actor::getCurrTile() const
{
    return currTile;
}

/**
 * @fn void Actor::updateCurrTile(void)
 * @brief updates currTile (current tile) based on x and y positions.
 * @param void
 * @return void
 */
void Actor::updateCurrTile(void)
{
    currTile = xPos/TILE_WIDTH + MAP_TILES_WIDTH * (yPos/TILE_HEIGHT);
}

/**
 * @fn void void Actor::moveLeft()
 * @brief Changes Actor x position by TILE_WIDTH to the left.
 * @param void
 * @return void
 */
void Actor::moveLeft()
{
    xPos -= TILE_WIDTH;
}

/**
 * @fn void Actor::moveRight()
 * @brief Changes Actor x position by TILE_WIDTH to the right.
 * @param void
 * @return void
 */
void Actor::moveRight()
{
    xPos += TILE_WIDTH;
}

/**
 * @fn void Actor::moveUp()
 * @brief Changes Actor y position by TILE_HEIGHT upwords.
 * @param void
 * @return void
 */
void Actor::moveUp()
{
    yPos -= TILE_HEIGHT;
}

/**
 * @fn void Actor::moveDown()
 * @brief Changes Actor y position by TILE_HEIGHT downwards.
 * @param void
 * @return void
 */
void Actor::moveDown()
{
    yPos += TILE_HEIGHT;
}

/**
 * @fn int Actor::getTileIndexLeft() const
 * @brief Returns position of the tile left to the Actor.
 * @param void
 * @return int currTile - 1
 */
int Actor::getTileIndexLeft() const
{
    return currTile - 1;
}

/**
 * @fn int Actor::getTileIndexRight() const
 * @brief Returns position of the tile right to the Actor.
 * @param void
 * @return int currTile + 1
 */
int Actor::getTileIndexRight() const
{
    return currTile + 1;
}

/**
 * @fn int Actor::getTileIndexUp() const
 * @brief Returns position of the tile upwards to the Actor.
 * @param void
 * @return int currTile - MAP_TILES_WIDTH
 */
int Actor::getTileIndexUp() const
{
    return currTile - MAP_TILES_WIDTH;
}

/**
 * @fn int Actor::getTileIndexDown() const
 * @brief Returns position of the tile downwards to the Actor.
 * @param void
 * @return return currTile + MAP_TILES_WIDTH
 */
int Actor::getTileIndexDown() const
{
    return currTile + MAP_TILES_WIDTH;
}

/**
 * @fn int Actor::getLastTile() const
 * @brief lastTile getter.
 * @param void
 * @return int lastTile
 */
int Actor::getLastTile() const
{
    return lastTile;
}

/**
 * @fn void Actor::setLastTile(int value)
 * @brief lastTile setter.
 * @param int lastTile
 * @return void
 */
void Actor::setLastTile(int value)
{
    lastTile = value;
}

/**
 * @fn int Actor::getSpeed() const
 * @brief speed getter.
 * @param void
 * @return int speed
 */
int Actor::getSpeed() const
{
    return speed;
}

/**
 * @fn void Actor::setSpeed(int value)
 * @brief speed setter.
 * @param int value
 * @return void
 */
void Actor::setSpeed(int value)
{
    speed = value;
}

/**
 * @fn int Actor::getDirection() const
 * @brief direction getter.
 * @param void
 * @return int direction
 */
int Actor::getDirection() const
{
    return direction;
}

/**
 * @fn void Actor::setDirection(int value)
 * @brief direction setter.
 * @param int value
 * @return void
 */
void Actor::setDirection(int value)
{
    direction = value;
}


