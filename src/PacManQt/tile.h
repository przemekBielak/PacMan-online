#ifndef TILE_H
#define TILE_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

#include "painter.h"

class Tile : public Painter
{
public:
    Tile();
    Tile(QString pixmapPath, int x, int y);
};

#endif // TILE_H
