#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

#include "game_cfg.h"
#include "actor.h"

/**
 * Pacman class inherits Actor class.
 * Class is responsible for controlling Ghosts.
 */
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
    /**
     * @var int numOfLifes
     * @brief Current number of lifes of pacman.
     */
    int numOfLifes;
    /**
     * @var int points
     * @brief Current number of points of pacman.
     */
    int points;
};

#endif // PACMAN_H
