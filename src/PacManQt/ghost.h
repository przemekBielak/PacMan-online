#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

#include "game_cfg.h"
#include "actor.h"

/**
 * Ghost class inherits Actor class.
 * Class is responsible for controlling Ghosts.
 */
class Ghost : public Actor
{
public:
    Ghost();
    Ghost(QString pixmapPath, int x, int y);
};

#endif // GHOST_H
