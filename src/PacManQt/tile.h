#ifndef TILE_H
#define TILE_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

class Tile
{
public:
    Tile();

    void setLocation(void);

    QPixmap *getPixmap() const;
    void setPixmap(QPixmap *value);

    QGraphicsPixmapItem *getPixmapItem() const;

    int getXPos() const;
    void setXPos(int value);

    int getYPos() const;
    void setYPos(int value);

private:
    QPixmap *pixmap;
    QGraphicsPixmapItem *pixmapItem;
    int xPos;
    int yPos;
};

#endif // TILE_H