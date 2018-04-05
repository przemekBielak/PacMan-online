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

/**
 * gameWindow controlls game logic, creates all actors and
 * maintains connection and data flow between server and client.
 */
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

    template <typename T>
    void checkDot(T *pac);
    void checkSuperDot(Pacman *pac);
    void checkLevelFinish(void);
    void updateTileGraphics(Pacman *pac);

    int gameLoopCounterGhost;
    int gameLoopCounterPacman;
    int gameLoopCounterPacman2;
    int gameLevel;

    void sendGameDataToClient(QByteArray string);
    void sendGameDataToServer(QByteArray string);

    void PackDataServerToClient(void);
    void UnpackDataServerToClient(void);
    void PackDataClientToServer(void);
    void UnpackDataClientToServer(void);
    
    /**
     * @var QTimer *gameLoopTimer
     * @brief Game loop timer - game is updated after each overflow.
     */
    QTimer *gameLoopTimer;

    /**
     * @var Ghost *ghostRed
     * @brief Red ghost object.
     */
    Ghost *ghostRed;
    /**
     * @var Ghost *ghostYellow
     * @brief Yellow ghost object.
     */
    Ghost *ghostYellow;
    /**
     * @var Ghost *ghostGreen
     * @brief Green ghost object.
     */
    Ghost *ghostGreen;
    /**
     * @var Ghost *ghostBlue
     * @brief Blue ghost object.
     */
    Ghost *ghostBlue;
    /**
     * @var Pacman *pacman
     * @brief Servers pacman object.
     */
    Pacman *pacman;
    /**
     * @var Pacman *pacman2
     * @brief Clients pacman object.
     */
    Pacman *pacman2;

    /**
     * @var serverWindow *gameServer
     * @brief server object which is communicating with client.
     */
    serverWindow *gameServer;
    /**
     * @var clientwindow *gameClient
     * @brief client object which is communicating with server.
     */
    clientwindow *gameClient;
    /**
     * @var connectionRoleType connectionRole
     * @brief Specifies if game was started as server or as client role.
     */
    connectionRoleType connectionRole;

protected:
    /**
     * @var QGraphicsScene *scene
     * @brief Game images are drawn on this scene.
     */
    QGraphicsScene *scene;
};

#endif // GAMEWINDOW_H
