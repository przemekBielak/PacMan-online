#ifndef ACTOR_H
#define ACTOR_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>

#include "game_cfg.h"
#include "painter.h"

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
    int currTile;
    int lastTile;
    int tileIndexLeft;
    int tileIndexRight;
    int tileIndexUp;
    int tileIndexDown;
    int speed;
    int direction;
};

#endif // ACTOR_H
