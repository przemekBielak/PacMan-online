#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

#include "actor.h"

class Pacman : public Actor
{
public:
    Pacman();
    Pacman(QString pixmapPath, int x, int y);
};

#endif // PACMAN_H
