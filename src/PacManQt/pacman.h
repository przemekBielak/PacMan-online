#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

#include "game_cfg.h"
#include "actor.h"

class Pacman : public Actor
{
public:
    Pacman();
    Pacman(QString pixmapPath, int x, int y);

    int getNumOfLifes() const;
    void setNumOfLifes(int value);

    int getPoints() const;
    void setPoints(int value);

private:
    int numOfLifes;
    int points;
};

#endif // PACMAN_H
