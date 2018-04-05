#include "gamewindow.h"
#include "ui_gamewindow.h"

/**
 * @var Tile $tileArr[]
 * @brief Stores tile type of specific array element.
 */
Tile tileArr[MAP_TILES_WIDTH * MAP_TILES_HEIGHT];

/**
 * @var int nonWalkableMapTiles[]
 * @brief Stores all tile numbers on which actor can't be placed.
 * @details Actor can't be placed on any wall tile type.
 */
int nonWalkableMapTiles[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

/**
 * @fn gameWindow(QWidget *parent = 0)
 * @brief gameWindow class constructor.
 * @details Constructor initializs graphics elements of game board,
 * initializes map tiles and adds actors to the board.
 * @param QWidget *parent
 * @retval void
 */
gameWindow::gameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameWindow)
{
    /* ui setup */
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    /* mapArr is storing types of all tiles */
    int mapArr[MAP_TILES_WIDTH * MAP_TILES_HEIGHT]
           = {1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 13, 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 ,
              4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              4 , 0 , 1 , 2 , 2 , 3 , 0 , 1 , 2 , 2 , 2 , 3 , 0 , 4 , 0 , 1 , 2 , 2 , 2 , 3 , 0 , 1 , 2 , 2 , 3 , 0 , 4 ,
              4 , 0 , 6 , 2 , 2 , 5 , 0 , 6 , 2 , 2 , 2 , 5 , 0 , 9 , 0 , 6 , 2 , 2 , 2 , 5 , 0 , 6 , 2 , 2 , 5 , 0 , 4 ,
              4 , 0 , 0 , 0 , 0 , 17, 0 , 17, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 17, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              4 , 0 , 10, 2 , 2 , 8 , 0 , 1 , 3 , 0 , 1 , 2 , 2 , 2 , 2 , 2 , 3 , 0 , 1 , 3 , 0 , 10, 2 , 2 , 8 , 0 , 4 ,
              4 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 4 , 0 , 6 , 2 , 3 , 0 , 1 , 2 , 5 , 0 , 4 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              6 , 2 , 2 , 2 , 2 , 3 , 0 , 4 , 4 , 0 , 0 , 0 , 4 , 0 , 4 , 0 , 0 , 0 , 4 , 4 , 0 , 1 , 2 , 2 , 2 , 2 , 5 ,
              0 , 0 , 0 , 0 , 0 , 4 , 18, 4 , 12, 2 , 8 , 17, 6 , 2 , 5 , 0 , 10, 2 , 14, 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 1 , 2 , 8 , 16, 10, 2 , 3 , 0 , 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              2 , 2 , 2 , 2 , 2 , 5 , 0 , 6 , 5 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 4 , 17, 6 , 5 , 0 , 6 , 2 , 2 , 2 , 2 , 2 ,
              0 , 0 , 0 , 0 , 0 , 0 , 0 , 17, 0 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
              2 , 2 , 2 , 2 , 2 , 3 , 0 , 1 , 3 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 4 , 0 , 1 , 3 , 0 , 1 , 2 , 2 , 2 , 2 , 2 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 6 , 2 , 2 , 2 , 2 , 2 , 5 , 0 , 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 18, 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 1 , 2 , 2 , 2 , 2 , 2 , 3 , 0 , 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              1 , 2 , 2 , 2 , 2 , 5 , 0 , 6 , 5 , 0 , 6 , 2 , 3 , 0 , 1 , 2 , 5 , 0 , 6 , 5 , 0 , 6 , 2 , 2 , 2 , 2 , 3 ,
              4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              4 , 0 , 1 , 2 , 2 , 3 , 17, 10, 2 , 2 , 8 , 0 , 6 , 2 , 5 , 0 , 10, 2 , 2 , 8 , 0 , 1 , 2 , 2 , 3 , 0 , 4 ,
              4 , 0 , 6 , 2 , 3 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 1 , 2 , 5 , 0 , 4 ,
              4 , 0 , 0 , 0 , 4 , 4 , 0 , 1 , 3 , 0 , 1 , 2 , 2 , 2 , 2 , 2 , 3 , 0 , 1 , 3 , 0 , 4 , 4 , 0 , 0 , 0 , 4 ,
              12, 2 , 8 , 0 , 6 , 5 , 0 , 4 , 4 , 0 , 6 , 2 , 3 , 0 , 1 , 2 , 5 , 0 , 4 , 4 , 0 , 6 , 5 , 0 , 10, 2 , 14 ,
              4 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 4 , 0 , 0 , 0 , 4 , 0 , 4 , 0 , 0 , 0 , 4 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              4 , 0 , 10, 2 , 2 , 2 , 2 , 11, 11, 2 , 8 , 0 , 6 , 2 , 5 , 0 , 10, 2 , 11, 11, 2 , 2 , 2 , 2 , 8 , 0 , 4,
              4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              6 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 5
            };


    QString pathImage;
    for(int i = 0; i < MAP_TILES_WIDTH * MAP_TILES_HEIGHT; i++)
    {
        switch(mapArr[i])
        {
            case 0:
                pathImage = ":/Images/white.png";
                break;
            case 1:
                pathImage = ":/Images/wall1.png";
                break;
            case 2:
                pathImage = ":/Images/wall2.png";
                break;
            case 3:
                pathImage = ":/Images/wall3.png";
                break;
            case 4:
                pathImage = ":/Images/wall4.png";
                break;
            case 5:
                pathImage = ":/Images/wall5.png";
                break;
            case 6:
                pathImage = ":/Images/wall6.png";
                break;
            case 7:
                pathImage = ":/Images/wall7.png";
                break;
            case 8:
                pathImage = ":/Images/wall8.png";
                break;
            case 9:
                pathImage = ":/Images/wall9.png";
                break;
            case 10:
                pathImage = ":/Images/wall10.png";
                break;
            case 11:
                pathImage = ":/Images/wall11.png";
                break;
            case 12:
                pathImage = ":/Images/wall12.png";
                break;
            case 13:
                pathImage = ":/Images/wall13.png";
                break;
            case 14:
                pathImage = ":/Images/wall14.png";
                break;
            case 15:
                pathImage = ":/Images/wall15.png";
                break;
            case 16:
              pathImage = ":/Images/fence.png";
              break;
            case 17:
                pathImage = ":/Images/rosekane_0.png";
                break;
            case 18:
                pathImage = ":/Images/superDot.png";
                break;
        }

        /* Add all tiles (with images) to the board */
        int x = i % MAP_TILES_WIDTH;
        int y = i / MAP_TILES_WIDTH;
        Tile currTile(pathImage, x * TILE_WIDTH, y * TILE_WIDTH);
        currTile.setTileType(mapArr[i]);
        tileArr[i] = currTile;
        scene->addItem(currTile.getPixmapItem());
    }

    /* Add all actors to the board */
    pacman = new Pacman(":/Images/pacmanRight.png", 20, 20);
    scene->addItem(pacman->getPixmapItem());

    pacman2 = new Pacman(":/Images/pacmanRight.png", 500, 500);
    scene->addItem(pacman2->getPixmapItem());

    ghostRed = new Ghost(":/Images/ghostRedRight.png", 100, 80);
    scene->addItem(ghostRed->getPixmapItem());

    ghostBlue = new Ghost(":/Images/ghostBlueRight.png", 200, 400);
    scene->addItem(ghostBlue->getPixmapItem());

    ghostYellow = new Ghost(":/Images/ghostYellowRight.png", 400, 80);
    scene->addItem(ghostYellow->getPixmapItem());

    ghostGreen = new Ghost(":/Images/ghostGreenRight.png", 400, 100);
    scene->addItem(ghostGreen->getPixmapItem());

    /* Set speed of each actor */
    pacman->setSpeed(10);
    pacman2->setSpeed(10);
    ghostBlue->setSpeed(30);

    ui->label_game_level_num->setText(QString::number(1));
}

/**
 * @fn void startGame(void)
 * @brief Start game timer.
 * @param void
 * @return void
 */
void gameWindow::startGame()
{
    /* Setup game timer */
    gameLoopTimer = new QTimer(this);
    connect(gameLoopTimer, SIGNAL(timeout()), this, SLOT(gameLoop()));

    /* Start game timer */
    gameLoopTimer->start(10);

}

/**
 * @fn ~gameWindow()
 * @brief gameWindow class deconstructor
 * @param void
 * @return void
 */
gameWindow::~gameWindow()
{
    delete ui;
}

/**
 * @fn keyPressEvent(QKeyEvent *event)
 * @brief Reads keyboard presses and sets pacman direction.
 * @details Based on connectionRole parameter (if player started game as host
 * or as client), keyboard presses will set direction of pacman or pacman2.
 * @param QKeyEvent *event
 * @return void
 */
void gameWindow::keyPressEvent(QKeyEvent *event)
{
    if(connectionRole == SERVER_ROLE)
    {
        if(event->key() == Qt::Key_A)
        {
            pacman->setDirection(DIRECTION_LEFT);
        }
        else if(event->key() == Qt::Key_D)
        {
            pacman->setDirection(DIRECTION_RIGHT);
        }
        else if(event->key() == Qt::Key_W)
        {
            pacman->setDirection(DIRECTION_UP);
        }
        else if(event->key() == Qt::Key_S)
        {
            pacman->setDirection(DIRECTION_DOWN);
        }
    }
    else if(connectionRole == CLIENT_ROLE)
    {
        if(event->key() == Qt::Key_A)
        {
            pacman2->setDirection(DIRECTION_LEFT);
        }
        else if(event->key() == Qt::Key_D)
        {
            pacman2->setDirection(DIRECTION_RIGHT);
        }
        else if(event->key() == Qt::Key_W)
        {
            pacman2->setDirection(DIRECTION_UP);
        }
        else if(event->key() == Qt::Key_S)
        {
            pacman2->setDirection(DIRECTION_DOWN);
        }
    }
}

/**
 * @fn void rotateImage(Actor *act)
 * @brief Rotate actor image based on direction paramter.
 * @param Actor *act
 * @return void
 */
void gameWindow::rotateImage(Actor *act)
{
    if(act->getDirection() == DIRECTION_LEFT)
    {
        act->setPixmap(":/Images/pacmanLeft.png");
    }
    else if(act->getDirection() == DIRECTION_RIGHT)
    {
        act->setPixmap(":/Images/pacmanRight.png");
    }
    else if(act->getDirection() == DIRECTION_UP)
    {
        act->setPixmap(":/Images/pacmanUp.png");
    }
    else if(act->getDirection() == DIRECTION_DOWN)
    {
        act->setPixmap(":/Images/pacmanDown.png");
    }
}

/**
 * @fn int checkIfMoveIsPossible(Actor *act, directionType direction)
 * @brief Checks if Actors move can be performed.
 * @details Checks if move in specified direction won't result in moving
 * Actor to the non-walkable field (for example wall).
 * @param Actor *act
 * @return int  - 0 - move not possible
 *                1 - move possible
 */
int gameWindow::checkIfMoveIsPossible(Actor *act, directionType direction)
{
    int currentTile;
    int *found;
    switch(direction)
    {
        case DIRECTION_LEFT:
            currentTile = tileArr[act->getTileIndexLeft()].getTileType();
            break;
        case DIRECTION_RIGHT:
            currentTile = tileArr[act->getTileIndexRight()].getTileType();
            break;
        case DIRECTION_UP:
            currentTile = tileArr[act->getTileIndexUp()].getTileType();
            break;
        case DIRECTION_DOWN:
            currentTile = tileArr[act->getTileIndexDown()].getTileType();
            break;
    }
    found = std::find(std::begin(nonWalkableMapTiles), std::end(nonWalkableMapTiles), currentTile);
    if(found == std::end(nonWalkableMapTiles))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @fn void setGhostDirection(Ghost *ghost)
 * @brief Updated ghost direction to follow pacman or pacman2.
 * @param Ghost *ghost
 * @return void
 */
void gameWindow::setGhostDirection(Ghost *ghost)
{
    if( (ghost->getYPos() == pacman->getYPos()) || (ghost->getYPos() == pacman2->getYPos()) )
    {
        if( (ghost->getXPos() > pacman->getXPos()) || (ghost->getXPos() > pacman2->getXPos()) )
        {
            ghost->setDirection(DIRECTION_LEFT);
        }
        else
        {
            ghost->setDirection(DIRECTION_RIGHT);
        }
    }
    else if( (ghost->getXPos() == pacman->getXPos()) || (ghost->getXPos() == pacman2->getXPos()) )
    {
        if( (ghost->getYPos() > pacman->getYPos()) || (ghost->getYPos() > pacman2->getYPos()) )
        {
            ghost->setDirection(DIRECTION_UP);
        }
        else
        {
            ghost->setDirection(DIRECTION_DOWN);
        }
    }
}

/**
 * @fn void moveActor(Actor *ghost)
 * @brief Moves actor on the boards if move is possible.
 * @details If Actors move is possible, it will be moved in the
 * specified direction. Actors x and y position will be updated.
 * @param Actor *actor
 * @return void
 */
void gameWindow::moveActor(Actor *actor)
{
    switch(actor->getDirection())
    {
        case DIRECTION_LEFT:
           if(checkIfMoveIsPossible(actor, DIRECTION_LEFT))
            {
                actor->moveLeft();
            }
            break;
        case DIRECTION_RIGHT:
            if(checkIfMoveIsPossible(actor, DIRECTION_RIGHT))
            {
                actor->moveRight();
            }
            break;
        case DIRECTION_UP:
            if(checkIfMoveIsPossible(actor, DIRECTION_UP))
            {
                actor->moveUp();
            }
            break;
        case DIRECTION_DOWN:
            if(checkIfMoveIsPossible(actor, DIRECTION_DOWN))
            {
                actor->moveDown();
            }
            break;
        case DONT_MOVE:
            break;
    }
}

/**
 * @fn void checkDot(T *pac)
 * @brief Checks if pacman has collected the dot.
 * @details If specified pacmans current tile is dot tile, pacmans score
 * will be incremented by one.
 * @param Pacman *pac
 * @return void
 */
template <typename T>
void gameWindow::checkDot(T *pac)
{
    if( (tileArr[pac->getCurrTile()].getTileType() == 17) && (pac->getLastTile() != pac->getCurrTile()) )
    {
        pac->setPoints(pac->getPoints() + 1);
    }
}

/**
 * @fn void checkSuperDot(Pacman *pac)
 * @brief Checks if pacman has collected the super dot.
 * @details If specified pacmans current tile is super dot tile, pacmans speed
 * will be incremented.
 * @param Pacman *pac
 * @return void
 */
void gameWindow::checkSuperDot(Pacman *pac)
{
    if( (tileArr[pac->getCurrTile()].getTileType() == 18) && (pac->getLastTile() != pac->getCurrTile()) )
    {
        pac->setSpeed(pac->getSpeed() - 5);
    }
}

/**
 * @fn void checkLevelFinish(void)
 * @brief Checks if all dots were collected from board.
 * @param void
 * @return void
 */
void gameWindow::checkLevelFinish()
{
    int endCounter = 0;
    for(int i = 0; i < MAP_TILES_WIDTH * MAP_TILES_HEIGHT; i++)
    {
        if(tileArr[i].getTileType() == 17)
        {
            /* Still dots left to be collected */
            endCounter ++;
        }
    }

    if(endCounter == 0)
    {
        ui->label_game_level_num->setText(QString::number(ui->label_game_level_num->text().toInt() + 1));
        endCounter == 0;
    }
}

/**
 * @fn void checkLevelFinish(void)
 * @brief Updates board graphics tile images when specified pacman eats dot.
 * @param Pacman *pac
 * @return void
 */
void gameWindow::updateTileGraphics(Pacman *pac)
{
    if(tileArr[pac->getCurrTile()].getTileType() == 17)
    {
        tileArr[pac->getCurrTile()].setTileType(0);
        tileArr[pac->getCurrTile()].setPixmap(":/Images/white.png");
    }

    if(tileArr[pac->getCurrTile()].getTileType() == 18)
    {
        tileArr[pac->getCurrTile()].setTileType(0);
        tileArr[pac->getCurrTile()].setPixmap(":/Images/white.png");
    }
}

/**
 * @fn clientwindow *getGameClient() const
 * @brief gameClient getter.
 */
clientwindow *gameWindow::getGameClient() const
{
    return gameClient;
}

/**
 * @fn void setGameClient(clientwindow *value)
 * @brief gameClient setter.
 */
void gameWindow::setGameClient(clientwindow *value)
{
    gameClient = value;
}

/**
 * @fn void sendGameDataToClient(QByteArray string)
 * @brief Sends data from Server to Client using Servers sendData function.
 * @param QByteArray string
 * @return void
 */
void gameWindow::sendGameDataToClient(QByteArray string)
{
    gameServer->sendData(string);
}

/**
 * @fn void sendGameDataToServer(QByteArray string);
 * @brief Sends data from Client to Server using Clients sendData function.
 * @param QByteArray string
 * @return void
 */
void gameWindow::sendGameDataToServer(QByteArray string)
{
    gameClient->sendData(string);
}

/**
 * @fn connectionRoleType getConnectionRole() const
 * @brief connectionRole getter.
 */
connectionRoleType gameWindow::getConnectionRole() const
{
    return connectionRole;
}

/**
 * @fn void setConnectionRole(const connectionRoleType &value)
 * @brief connectionRole setter.
 */
void gameWindow::setConnectionRole(const connectionRoleType &value)
{
    connectionRole = value;
}

/**
 * @fn serverWindow *getGameServer() const;
 * @brief gameServer getter.
 */
serverWindow *gameWindow::getGameServer() const
{
    return gameServer;
}

/**
 * @fn void setGameServer(serverWindow *value);
 * @brief gameServer setter.
 */
void gameWindow::setGameServer(serverWindow *value)
{
    gameServer = value;
}

/**
 * @fn void checkIfDead(Pacman *pac)
 * @brief Check if specified pacman is dead.
 * @details Checks if specified pacman position is the same as ghost position.
 * If so, pacman number of lives is decremented and is setup to start position on board.
 * @param Pacman *pac
 * @return void
 */
void gameWindow::checkIfDead(Pacman *pac)
{
    if( (pac->getCurrTile() == ghostRed->getCurrTile() ) ||
        (pac->getCurrTile() == ghostBlue->getCurrTile() ) ||
        (pac->getCurrTile() == ghostGreen->getCurrTile() ) ||
        (pac->getCurrTile() == ghostYellow->getCurrTile() ) )
    {
        pac->setNumOfLifes(pac->getNumOfLifes() - 1);
        pac->setLocation(20, 20);
    }
}

/**
 * @fn void PackDataServerToClient(void)
 * @brief Prepares and sends data from server to client.
 * @details Function initializes QByteArray array with all game details which
 * have to be sent from server to client. Server is responsible for updating
 * game logic, which is sent to client.
 * @param void
 * @return void
 */
void gameWindow::PackDataServerToClient()
{
    /* Server send */
    QByteArray arr;
    arr.resize(28);

    /* Store all data to be sent */
    quint16 pacmanxpos = static_cast<quint16>(pacman->getXPos());
    quint16 pacmanypos = static_cast<quint16>(pacman->getYPos());
    quint16 pacman2xpos = static_cast<quint16>(pacman2->getXPos());
    quint16 pacman2ypos = static_cast<quint16>(pacman2->getYPos());
    quint16 ghostRedxpos = static_cast<quint16>(ghostRed->getXPos());
    quint16 ghostRedypos = static_cast<quint16>(ghostRed->getYPos());
    quint16 ghostBluexpos = static_cast<quint16>(ghostBlue->getXPos());
    quint16 ghostBlueypos = static_cast<quint16>(ghostBlue->getYPos());
    quint16 ghostGreenxpos = static_cast<quint16>(ghostGreen->getXPos());
    quint16 ghostGreenypos = static_cast<quint16>(ghostGreen->getYPos());
    quint16 ghostYellowxpos = static_cast<quint16>(ghostYellow->getXPos());
    quint16 ghostYellowypos = static_cast<quint16>(ghostYellow->getYPos());

    /* Update array */
    arr[0] = pacman->getDirection();
    arr[1] = pacmanxpos >> 8;
    arr[2] = static_cast<quint8>(pacmanxpos);
    arr[3] = pacmanypos >> 8;
    arr[4] = static_cast<quint8>(pacmanypos);
    arr[5] = pacman2xpos >> 8;
    arr[6] = static_cast<quint8>(pacman2xpos);
    arr[7] = pacman2ypos >> 8;
    arr[8] = static_cast<quint8>(pacman2ypos);
    arr[9] = ghostRedxpos >> 8;
    arr[10] = static_cast<quint8>(ghostRedxpos);
    arr[11] = ghostRedypos >> 8;
    arr[12] = static_cast<quint8>(ghostRedypos);
    arr[13] = ghostBluexpos >> 8;
    arr[14] = static_cast<quint8>(ghostBluexpos);
    arr[15] = ghostBlueypos >> 8;
    arr[16] = static_cast<quint8>(ghostBlueypos);
    arr[17] = ghostGreenxpos >> 8;
    arr[18] = static_cast<quint8>(ghostGreenxpos);
    arr[19] = ghostGreenypos >> 8;
    arr[20] = static_cast<quint8>(ghostGreenypos);
    arr[21] = ghostYellowxpos >> 8;
    arr[22] = static_cast<quint8>(ghostYellowxpos);
    arr[23] = ghostYellowypos >> 8;
    arr[24] = static_cast<quint8>(ghostYellowypos);
    arr[25] = pacman->getNumOfLifes();
    arr[26] = pacman2->getNumOfLifes();
    arr[27] = pacman->getPoints();
    arr[28] = pacman2->getPoints();

    /* Send data to client */
    sendGameDataToClient(arr);
}

/**
 * @fn void UnpackDataServerToClient(void);
 * @brief Unpacks data sent from server.
 * @details Updates clients data based on received data from server.
 * @param void
 * @return void
 */
void gameWindow::UnpackDataServerToClient()
{
    /* Client receive */
    QByteArray arr;
    arr.resize(28);

    arr = gameClient->getReceivedData();

    pacman->setDirection(static_cast<quint8>(arr[0]));

    quint16 recPacmanxPos = 0;
    recPacmanxPos |= static_cast<quint8>(arr[1]) << 8;
    recPacmanxPos |= static_cast<quint8>(arr[2]);
    pacman->setXPos(recPacmanxPos);

    quint16 recPacmanyPos = 0;
    recPacmanyPos |= static_cast<quint8>(arr[3]) << 8;
    recPacmanyPos |= static_cast<quint8>(arr[4]);
    pacman->setYPos(recPacmanyPos);

    quint16 recPacman2xPos = 0;
    recPacman2xPos |= static_cast<quint8>(arr[5]) << 8;
    recPacman2xPos |= static_cast<quint8>(arr[6]);
    pacman2->setXPos(recPacman2xPos);

    quint16 recPacman2yPos = 0;
    recPacman2yPos |= static_cast<quint8>(arr[7]) << 8;
    recPacman2yPos |= static_cast<quint8>(arr[8]);
    pacman2->setYPos(recPacman2yPos);

    quint16 ghostRedxPos = 0;
    ghostRedxPos |= static_cast<quint8>(arr[9]) << 8;
    ghostRedxPos |= static_cast<quint8>(arr[10]);
    ghostRed->setXPos(ghostRedxPos);

    quint16 ghostRedyPos = 0;
    ghostRedyPos |= static_cast<quint8>(arr[11]) << 8;
    ghostRedyPos |= static_cast<quint8>(arr[12]);
    ghostRed->setYPos(ghostRedyPos);

    quint16 ghostBluexPos = 0;
    ghostBluexPos |= static_cast<quint8>(arr[13]) << 8;
    ghostBluexPos |= static_cast<quint8>(arr[14]);
    ghostBlue->setXPos(ghostBluexPos);

    quint16 ghostBlueyPos = 0;
    ghostBlueyPos |= static_cast<quint8>(arr[15]) << 8;
    ghostBlueyPos |= static_cast<quint8>(arr[16]);
    ghostBlue->setYPos(ghostBlueyPos);

    quint16 ghostGreenxPos = 0;
    ghostGreenxPos |= static_cast<quint8>(arr[17]) << 8;
    ghostGreenxPos |= static_cast<quint8>(arr[18]);
    ghostGreen->setXPos(ghostGreenxPos);

    quint16 ghostGreenyPos = 0;
    ghostGreenyPos |= static_cast<quint8>(arr[19]) << 8;
    ghostGreenyPos |= static_cast<quint8>(arr[20]);
    ghostGreen->setYPos(ghostGreenyPos);

    quint16 ghostYellowxPos = 0;
    ghostYellowxPos |= static_cast<quint8>(arr[21]) << 8;
    ghostYellowxPos |= static_cast<quint8>(arr[22]);
    ghostYellow->setXPos(ghostYellowxPos);

    quint16 ghostYellowyPos = 0;
    ghostYellowyPos |= static_cast<quint8>(arr[23]) << 8;
    ghostYellowyPos |= static_cast<quint8>(arr[24]);
    ghostYellow->setYPos(ghostYellowyPos);

    pacman->setNumOfLifes(static_cast<quint8>(arr[25]));
    pacman2->setNumOfLifes(static_cast<quint8>(arr[26]));

    pacman->setPoints(static_cast<quint8>(arr[27]));
    pacman2->setPoints(static_cast<quint8>(arr[28]));
}

/**
 * @fn void PackDataClientToServer(void);
 * @brief Function sends pacman2 direction to server.
 * @param void
 * @return void
 */
void gameWindow::PackDataClientToServer()
{
    /* Client send */
    QByteArray arr;
    arr.resize(1);

    arr[0] = pacman2->getDirection();
    sendGameDataToServer(arr);
}

/**
 * @fn void UnpackDataClientToServer(void)
 * @brief Function updates servers pacman2 direction from client data.
 * @param void
 * @return void
 */
void gameWindow::UnpackDataClientToServer()
{
    /* Server receive */
    QByteArray arr;
    arr.resize(1);

    arr = gameServer->getReceivedData();
    pacman2->setDirection(static_cast<quint8>(arr[0]));
}

/**
 * @fn void gameLoop(void);
 * @brief Game loop - updates game states and variables.
 * @details This function is a slot for Timer. This
 * function is called after each Timer overflow.
 * Game logic is based on connectionRole.
 * Part of the gameloop is executed on server and part on client side.
 * @param void
 * @return void
 */
void gameWindow::gameLoop(void)
{
    /* On client side, unpack and update game state based on server data
     * and send data to server.
     */
    if(connectionRole == CLIENT_ROLE)
    {
        UnpackDataServerToClient();
        PackDataClientToServer();
    }

    /* Update game loop counters of each actor */
    gameLoopCounterPacman++;
    gameLoopCounterPacman2++;
    gameLoopCounterGhost++;

    /* Update tile position of each actor */
    pacman->updateCurrTile();
    pacman2->updateCurrTile();
    ghostBlue->updateCurrTile();
    ghostRed->updateCurrTile();
    ghostGreen->updateCurrTile();
    ghostYellow->updateCurrTile();

    /* Update pacman fields */
    ui->label_lifes_num->setText(QString::number(pacman->getNumOfLifes()));
    ui->label_points->setText(QString::number(pacman->getPoints()));

    ui->label_lifes_num_2->setText(QString::number(pacman2->getNumOfLifes()));
    ui->label_points_2->setText(QString::number(pacman2->getPoints()));

    /* On server side, check if any pacman has died or has collected points. */
    if(connectionRole == SERVER_ROLE)
    {
        /* Check ghost tile */
        checkIfDead(pacman);
        checkIfDead(pacman2);

        /* Check points tile */
        checkDot(pacman);
        checkDot(pacman2);

        /* Check super dot tile */
        checkSuperDot(pacman);
        checkSuperDot(pacman2);
    }

    /* Update tile graphics based on both pacmans behaviours */
    updateTileGraphics(pacman);
    updateTileGraphics(pacman2);


    /* Rotate pacmans */
    rotateImage(pacman);
    rotateImage(pacman2);

    /* Pacman game loop */
    if(gameLoopCounterPacman > pacman->getSpeed())
    {
        if(connectionRole == SERVER_ROLE)
        {
            moveActor(pacman);
        }
        pacman->setDirection(DONT_MOVE);
        pacman->updatePos();
        pacman->setLastTile(pacman->getCurrTile());
        gameLoopCounterPacman = 0;
    }

    /* Pacman2 game loop */
    if(gameLoopCounterPacman2 > pacman2->getSpeed())
    {
        if(connectionRole == SERVER_ROLE)
        {
            moveActor(pacman2);
        }
        pacman2->setDirection(DONT_MOVE);
        pacman2->updatePos();
        pacman2->setLastTile(pacman->getCurrTile());
        gameLoopCounterPacman2 = 0;
    }

    /* Ghost game loop */
    if(gameLoopCounterGhost > ghostBlue->getSpeed())
    {
        /* Set ghost direction */
        setGhostDirection(ghostRed);
        setGhostDirection(ghostBlue);
        setGhostDirection(ghostGreen);
        setGhostDirection(ghostYellow);

        /* Move ghost */
        if(connectionRole == SERVER_ROLE)
        {
            moveActor(ghostRed);
            moveActor(ghostBlue);
            moveActor(ghostGreen);
            moveActor(ghostYellow);
        }
        ghostRed->updatePos();
        ghostBlue->updatePos();
        ghostGreen->updatePos();
        ghostYellow->updatePos();
        gameLoopCounterGhost = 0;
    }

    checkLevelFinish();

    /* On server side, receive pacman2 direction and send all game data to client. */
    if(connectionRole == SERVER_ROLE)
    {
        UnpackDataClientToServer();
        PackDataServerToClient();
    }

    /* Update QGraphicsScene object */
    scene->update();
}


