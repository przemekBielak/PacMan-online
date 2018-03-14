#ifndef TILE_H
#define TILE_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

class Tile
{
public:
    Tile();

    QPixmap *pixmap;
    QGraphicsPixmapItem *pixmapItem;
    setLocation(int x, int y);

private:
    int xPos;
    int yPos;
};

#endif // TILE_H
