#include "painter.h"

/**
 * @fn Painter()
 * @brief Empty Painter class constructor.
 * @param void
 * @return void
 */
Painter::Painter()
{
    /* */
}

/**
 * @fn Painter()
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
 * @fn void updatePos(void)
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
 * @fn void setLocation(void)
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
 * @fn QPixmap *getPixmap() const
 * @brief pixmap getter.
 */
QPixmap *Painter::getPixmap() const
{
    return pixmap;
}

/**
 * @fn void setPixmap(QString value)
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
 * @fn QGraphicsPixmapItem *getPixmapItem() const
 * @brief pixmapItem getter.
 */
QGraphicsPixmapItem *Painter::getPixmapItem() const
{
    return pixmapItem;
}

/**
 * @fn int getXPos() const
 * @brief xPos getter.
 */
int Painter::getXPos() const
{
    return xPos;
}

/**
 * @fn void setXPos(int value)
 * @brief xPos setter.
 */
void Painter::setXPos(int value)
{
    xPos = value;
}

/**
 * @fn int getYPos() const
 * @brief yPos getter.
 */
int Painter::getYPos() const
{
    return yPos;
}

/**
 * @fn void setYPos(int value)
 * @brief yPos setter.
 */
void Painter::setYPos(int value)
{
    yPos = value;
}
