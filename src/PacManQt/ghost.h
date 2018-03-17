#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

#include "actor.h"

class Ghost : public Actor
{
public:
    Ghost();
    Ghost(QString pixmapPath, int x, int y);
};

#endif // GHOST_H
