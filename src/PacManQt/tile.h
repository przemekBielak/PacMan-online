#ifndef TILE_H
#define TILE_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

#include "game_cfg.h"
#include "painter.h"

class Tile : public Painter
{
public:
    Tile();
    Tile(QString pixmapPath, int x, int y);

    int getTileType() const;
    void setTileType(int value);

private:

    /**
     * @var int tileType
     * @brief tileType stores type of tile, like wall, dot etc.
     */
    int tileType;
};

#endif // TILE_H
