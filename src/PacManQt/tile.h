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

    int getTileType() const;
    void setTileType(int value);

private:
    int tileType;
};

#endif // TILE_H
