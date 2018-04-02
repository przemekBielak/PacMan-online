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
#include <QByteArray>

#include "game_cfg.h"
#include "tile.h"
#include "actor.h"
#include "pacman.h"
#include "ghost.h"
#include "globaltypes.h"
#include "serverwindow.h"
#include "clientwindow.h"
#include "gameoptions.h"


namespace Ui {
class gameWindow;
}

class gameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit gameWindow(QWidget *parent = 0);
    ~gameWindow();
    void startGame(void);

    serverWindow *getGameServer() const;
    void setGameServer(serverWindow *value);

    clientwindow *getGameClient() const;
    void setGameClient(clientwindow *value);

    connectionRoleType getConnectionRole() const;
    void setConnectionRole(const connectionRoleType &value);

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

    QTimer *gameLoopTimer;

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

    serverWindow *gameServer;
    clientwindow *gameClient;
    void sendGameDataToClient(QByteArray string);
    void sendGameDataToServer(QByteArray string);

    connectionRoleType connectionRole;

protected:
    QGraphicsScene *scene;
};

#endif // GAMEWINDOW_H
