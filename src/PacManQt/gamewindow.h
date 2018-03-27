#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QImage>
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>

#include "game_cfg.h"
#include "tile.h"
#include "actor.h"
#include "pacman.h"
#include "ghost.h"
#include "gameoptions.h"

typedef enum directionType_
{
        DIRECTION_LEFT = 0
    ,   DIRECTION_RIGHT
    ,   DIRECTION_UP
    ,   DIRECTION_DOWN
    ,   DONT_MOVE
}directionType;



namespace Ui {
class gameWindow;
}

class gameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit gameWindow(QWidget *parent = 0);
    ~gameWindow();

    QTimer *gameLoopTimer;

public slots:
    void gameLoop(void);

private:
    Ui::gameWindow *ui;

    void keyPressEvent(QKeyEvent *event);
    int checkIfMoveIsPossible(Actor *act, directionType direction);
    void setGhostDirection(Ghost *ghost);
    void rotateImage(Actor *act);
    void moveActor(Actor *ghost);
    void checkIfDead(Pacman *pac);
    void checkDot(Pacman *pac);
    void checkSuperDot(Pacman *pac);
    void checkLevelFinish(void);

    Ghost *ghostRed;
    Ghost *ghostYellow;
    Ghost *ghostGreen;
    Ghost *ghostBlue;
    Pacman *pacman;
    Pacman *pacman2;
    int gameLoopCounterGhost;
    int gameLoopCounterPacman;
    int gameLoopCounterPacman2;
    int gameLevel;

protected:
    QGraphicsScene *scene;
};

#endif // GAMEWINDOW_H
