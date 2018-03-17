#ifndef PAINTER_H
#define PAINTER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

class Painter
{
public:
    Painter();
    Painter(QString pixmapPath, int x, int y);

    void setLocation(int x, int y);

    QPixmap *getPixmap() const;
    void setPixmap(QString value);

    QGraphicsPixmapItem *getPixmapItem() const;

    int getXPos() const;
    void setXPos(int value);

    int getYPos() const;
    void setYPos(int value);

protected:
    QPixmap *pixmap;
    QGraphicsPixmapItem *pixmapItem;
    int xPos;
    int yPos;
};

#endif // PAINTER_H
