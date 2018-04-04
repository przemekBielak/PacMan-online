#ifndef ACTOR_H
#define ACTOR_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

#include "game_cfg.h"
#include "painter.h"

/**
 * Actor class is responsible for moving and controlling all
 * Actors (Pacman or Ghost).
 */
class Actor : public Painter
{
public:
    Actor();
    Actor(QString pixmapPath, int x, int y);

    int getCurrTile() const;
    void updateCurrTile(void);

    void moveLeft(void);
    void moveRight(void);
    void moveUp(void);
    void moveDown(void);


    int getTileIndexLeft() const;
    int getTileIndexRight() const;
    int getTileIndexUp() const;
    int getTileIndexDown() const;

    int getLastTile() const;
    void setLastTile(int value);

    int getSpeed() const;
    void setSpeed(int value);

    int getDirection() const;
    void setDirection(int value);

private:
    /**
     * @var currTile
     * @brief Tile on which currently stays Actor.
     */
    int currTile;
    /**
     * @var lastTile
     * @brief Tile on which Actor stayed last time.
     */
    int lastTile;
    /**
     * @var tileIndexLeft
     * @brief Tile index to the left of Actor.
     */
    int tileIndexLeft;
    /**
     * @var tileIndexRight
     * @brief Tile index to the right of Actor.
     */
    int tileIndexRight;
    /**
     * @var tileIndexUp
     * @brief Tile index upward of Actor.
     */
    int tileIndexUp;
    /**
     * @var tileIndexDown
     * @brief Tile index downward of Actor.
     */
    int tileIndexDown;
    /**
     * @var speed
     * @brief Speed of Actor.
     */
    int speed;
    /**
     * @var direction
     * @brief Set direction of Actor.
     */
    int direction;
};

#endif // ACTOR_H
