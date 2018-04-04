#ifndef PAINTER_H
#define PAINTER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

#include "game_cfg.h"

/** Painter class is responsible for drawing all images. */
class Painter
{
public:
    Painter();
    Painter(QString pixmapPath, int x, int y);

    void updatePos(void);
    void setLocation(int x, int y);

    QPixmap *getPixmap() const;
    void setPixmap(QString value);

    QGraphicsPixmapItem *getPixmapItem() const;

    int getXPos() const;
    void setXPos(int value);

    int getYPos() const;
    void setYPos(int value);

protected:
    /**
     * @var QPixmap *pixmap
     * @brief pixmap is storing image.
     */
    QPixmap *pixmap;
    /**
     * @var QGraphicsPixmapItem *pixmapItem
     * @brief pixmap is storing image - used on QGraphicsScene.
     */
    QGraphicsPixmapItem *pixmapItem;
    /**
     * @var int xPos
     * @brief x position.
     */
    int xPos;
    /**
     * @var int yPos
     * @brief y position.
     */
    int yPos;
};

#endif // PAINTER_H
