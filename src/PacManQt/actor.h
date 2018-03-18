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

private:
    int currTile;
    int tileIndexLeft;
    int tileIndexRight;
    int tileIndexUp;
    int tileIndexDown;
};

#endif // ACTOR_H
