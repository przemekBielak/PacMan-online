#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

#include "game_cfg.h"
#include "actor.h"

class Ghost : public Actor
{
public:
    Ghost();
    Ghost(QString pixmapPath, int x, int y);

    int getDirection() const;
    void setDirection(int value);

protected:
    int direction;
};

#endif // GHOST_H
