#ifndef ACTOR_H
#define ACTOR_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

#include "painter.h"

class Actor : public Painter
{
public:
    Actor();
    Actor(QString pixmapPath, int x, int y);
};

#endif // ACTOR_H
