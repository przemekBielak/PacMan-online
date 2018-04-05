#include "painter.h"

/** @file painter.cpp */

/**
 * @fn Painter::Painter()
 * @brief Empty Painter class constructor.
 * @param void
 * @return void
 */
Painter::Painter()
{
    /* */
}

/**
 * @fn Painter::Painter(QString pixmapPath, int x, int y)
 * @brief Overloaded Painter class constructor.
 * @details Updates graphics, sets x and y positions.
 * @param QString pixmapPath, int x, int y
 * @return void
 */
Painter::Painter(QString pixmapPath, int x, int y)
{
    pixmap = new QPixmap(pixmapPath);
    pixmapItem = new QGraphicsPixmapItem(*pixmap);
    xPos = x;
    yPos = y;
    pixmapItem->setPos(xPos, yPos);
}

/**
 * @fn void Painter::updatePos(void)
 * @brief Updates graphics
 * @details Updates pixmap location based on x and y coordinates.
 * @param void
 * @return void
 */
void Painter::updatePos(void)
{
    pixmapItem->setPos(xPos, yPos);
}

/**
 * @fn void Painter::setLocation(int x, int y)
 * @brief Sets x and y position.
 * @param int x, int y
 * @return void
 */
void Painter::setLocation(int x, int y)
{
    xPos = x;
    yPos = y;
}

/**
 * @fn QPixmap *Painter::getPixmap() const
 * @brief pixmap getter.
 */
QPixmap *Painter::getPixmap() const
{
    return pixmap;
}

/**
 * @fn void Painter::setPixmap(QString value)
 * @brief pixmap setter.
 */
void Painter::setPixmap(QString value)
{
    QPixmap *pix = new QPixmap(value);
    pixmap = pix;
    /* Set pixmapItem from specified pixmap */
    pixmapItem->setPixmap(*pix);
}

/**
 * @fn QGraphicsPixmapItem *Painter::getPixmapItem() const
 * @brief pixmapItem getter.
 */
QGraphicsPixmapItem *Painter::getPixmapItem() const
{
    return pixmapItem;
}

/**
 * @fn int Painter::getXPos() const
 * @brief xPos getter.
 */
int Painter::getXPos() const
{
    return xPos;
}

/**
 * @fn void Painter::setXPos(int value)
 * @brief xPos setter.
 */
void Painter::setXPos(int value)
{
    xPos = value;
}

/**
 * @fn int Painter::getYPos() const
 * @brief yPos getter.
 */
int Painter::getYPos() const
{
    return yPos;
}

/**
 * @fn void Painter::setYPos(int value)
 * @brief yPos setter.
 */
void Painter::setYPos(int value)
{
    yPos = value;
}
