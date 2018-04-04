#include "actor.h"

/**
 * @fn Actor()
 * @brief Empty actor class constructor.
 * @param void
 * @return void
 */
Actor::Actor()
{
    /* */
}

/**
 * @fn Actor()
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
 * @fn int getCurrTile() const
 * @brief currTile getter.
 */
int Actor::getCurrTile() const
{
    return currTile;
}

/**
 * @fn void updateCurrTile(void)
 * @brief updates currTile (current tile) based on x and y positions.
 * @param void
 * @return void
 */
void Actor::updateCurrTile(void)
{
    currTile = xPos/TILE_WIDTH + MAP_TILES_WIDTH * (yPos/TILE_HEIGHT);
}

/**
 * @fn void moveLeft(void)
 * @brief Changes Actor x position by TILE_WIDTH to the left.
 * @param void
 * @return void
 */
void Actor::moveLeft()
{
    xPos -= TILE_WIDTH;
}

/**
 * @fn void moveRight(void)
 * @brief Changes Actor x position by TILE_WIDTH to the right.
 * @param void
 * @return void
 */
void Actor::moveRight()
{
    xPos += TILE_WIDTH;
}

/**
 * @fn void moveUp(void)
 * @brief Changes Actor y position by TILE_HEIGHT upwords.
 * @param void
 * @return void
 */
void Actor::moveUp()
{
    yPos -= TILE_HEIGHT;
}

/**
 * @fn void moveDown(void)
 * @brief Changes Actor y position by TILE_HEIGHT downwards.
 * @param void
 * @return void
 */
void Actor::moveDown()
{
    yPos += TILE_HEIGHT;
}

/**
 * @fn int getTileIndexLeft() const
 * @brief Returns position of the tile left to the Actor.
 * @param int
 * @return void
 */
int Actor::getTileIndexLeft() const
{
    return currTile - 1;
}

/**
 * @fn int getTileIndexRight() const
 * @brief Returns position of the tile right to the Actor.
 * @param int
 * @return void
 */
int Actor::getTileIndexRight() const
{
    return currTile + 1;
}

/**
 * @fn int getTileIndexUp() const
 * @brief Returns position of the tile upwards to the Actor.
 * @param int
 * @return void
 */
int Actor::getTileIndexUp() const
{
    return currTile - MAP_TILES_WIDTH;
}

/**
 * @fn int getTileIndexDown() const
 * @brief Returns position of the tile downwards to the Actor.
 * @param int
 * @return void
 */
int Actor::getTileIndexDown() const
{
    return currTile + MAP_TILES_WIDTH;
}

/**
 * @fn int getLastTile() const
 * @brief lastTile getter.
 */
int Actor::getLastTile() const
{
    return lastTile;
}

/**
 * @fn void setLastTile(int value)
 * @brief lastTile setter.
 */
void Actor::setLastTile(int value)
{
    lastTile = value;
}

/**
 * @fn int getSpeed() const
 * @brief speed getter.
 */
int Actor::getSpeed() const
{
    return speed;
}

/**
 * @fn int setSpeed() const
 * @brief speed setter.
 */
void Actor::setSpeed(int value)
{
    speed = value;
}

/**
 * @fn int getDirection() const
 * @brief direction getter.
 */
int Actor::getDirection() const
{
    return direction;
}

/**
 * @fn int setDirection() const
 * @brief direction setter.
 */
void Actor::setDirection(int value)
{
    direction = value;
}


