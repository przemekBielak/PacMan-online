#include "mainwindow.h"
#include "ui_mainwindow.h"

/* tileArr is storing all tiles */
Tile tileArr[MAP_TILES_WIDTH * MAP_TILES_HEIGHT];
int nonWalkableMapTiles[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

int lastTile;
int lastTileType;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    gameLoopTimer = new QTimer(this);
    connect(gameLoopTimer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    gameLoopTimer->start(500);

    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    /* mapArr is storing types of all tiles */
    int mapArr[MAP_TILES_WIDTH * MAP_TILES_HEIGHT]
           = {1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 13, 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 ,
              4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              4 , 0 , 1 , 2 , 2 , 3 , 0 , 1 , 2 , 2 , 2 , 3 , 0 , 4 , 0 , 1 , 2 , 2 , 2 , 3 , 0 , 1 , 2 , 2 , 3 , 0 , 4 ,
              4 , 0 , 6 , 2 , 2 , 5 , 0 , 6 , 2 , 2 , 2 , 5 , 0 , 9 , 0 , 6 , 2 , 2 , 2 , 5 , 0 , 6 , 2 , 2 , 5 , 0 , 4 ,
              4 , 0 , 0 , 0 , 0 , 17, 0 , 17, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              4 , 0 , 10, 2 , 2 , 8 , 0 , 1 , 3 , 0 , 1 , 2 , 2 , 2 , 2 , 2 , 3 , 0 , 1 , 3 , 0 , 10, 2 , 2 , 8 , 0 , 4 ,
              4 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 4 , 0 , 6 , 2 , 3 , 0 , 1 , 2 , 5 , 0 , 4 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              6 , 2 , 2 , 2 , 2 , 3 , 0 , 4 , 4 , 0 , 0 , 0 , 4 , 0 , 4 , 0 , 0 , 0 , 4 , 4 , 0 , 1 , 2 , 2 , 2 , 2 , 5 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 12, 2 , 8 , 17, 6 , 2 , 5 , 0 , 10, 2 , 14, 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 1 , 2 , 8 , 16, 10, 2 , 3 , 0 , 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              2 , 2 , 2 , 2 , 2 , 5 , 0 , 6 , 5 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 4 , 0 , 6 , 5 , 0 , 6 , 2 , 2 , 2 , 2 , 2 ,
              0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
              2 , 2 , 2 , 2 , 2 , 3 , 0 , 1 , 3 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 4 , 0 , 1 , 3 , 0 , 1 , 2 , 2 , 2 , 2 , 2 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 6 , 2 , 2 , 2 , 2 , 2 , 5 , 0 , 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 1 , 2 , 2 , 2 , 2 , 2 , 3 , 0 , 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              1 , 2 , 2 , 2 , 2 , 5 , 0 , 6 , 5 , 0 , 6 , 2 , 3 , 0 , 1 , 2 , 5 , 0 , 6 , 5 , 0 , 6 , 2 , 2 , 2 , 2 , 3 ,
              4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              4 , 0 , 1 , 2 , 2 , 3 , 0 , 10, 2 , 2 , 8 , 0 , 6 , 2 , 5 , 0 , 10, 2 , 2 , 8 , 0 , 1 , 2 , 2 , 3 , 0 , 4 ,
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
        }

        int x = i % MAP_TILES_WIDTH;
        int y = i / MAP_TILES_WIDTH;
        Tile currTile(pathImage, x * TILE_WIDTH, y * TILE_WIDTH);
        currTile.setTileType(mapArr[i]);
        tileArr[i] = currTile;
        scene->addItem(currTile.getPixmapItem());
    }

    pacman = new Pacman(":/Images/pacmanRight.png", 20, 20);
    scene->addItem(pacman->getPixmapItem());

    ghostRed = new Ghost(":/Images/ghostRedRight.png", 100, 80);
    scene->addItem(ghostRed->getPixmapItem());

    ghostBlue = new Ghost(":/Images/ghostBlueRight.png", 200, 400);
    scene->addItem(ghostBlue->getPixmapItem());

    ghostYellow = new Ghost(":/Images/ghostYellowRight.png", 400, 100);
    scene->addItem(ghostYellow->getPixmapItem());

    ghostGreen = new Ghost(":/Images/ghostGreenRight.png", 400, 100);
    scene->addItem(ghostGreen->getPixmapItem());
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {
        pacman->setPixmap(":/Images/pacmanUp.png");
        int currentTile = tileArr[pacman->getTileIndexUp()].getTileType();
        int *found = std::find(std::begin(nonWalkableMapTiles), std::end(nonWalkableMapTiles), currentTile);
        if(found == std::end(nonWalkableMapTiles))
        {
            pacman->moveUp();
            scene->update();
        }
    }
    else if(event->key() == Qt::Key_A)
    {
        pacman->setPixmap(":/Images/pacmanLeft.png");
        int currentTile = tileArr[pacman->getTileIndexLeft()].getTileType();
        int *found = std::find(std::begin(nonWalkableMapTiles), std::end(nonWalkableMapTiles), currentTile);
        if(found == std::end(nonWalkableMapTiles))
        {
            pacman->moveLeft();
            scene->update();
        }
    }
    else if(event->key() == Qt::Key_S)
    {
        pacman->setPixmap(":/Images/pacmanDown.png");
        int currentTile = tileArr[pacman->getTileIndexDown()].getTileType();
        int *found = std::find(std::begin(nonWalkableMapTiles), std::end(nonWalkableMapTiles), currentTile);
        if(found == std::end(nonWalkableMapTiles))
        {
            pacman->moveDown();
            scene->update();
        }
    }
    else if(event->key() == Qt::Key_D)
    {
        pacman->setPixmap(":/Images/pacmanRight.png");
        int currentTile = tileArr[pacman->getTileIndexRight()].getTileType();
        int *found = std::find(std::begin(nonWalkableMapTiles), std::end(nonWalkableMapTiles), currentTile);
        if(found == std::end(nonWalkableMapTiles))
        {
            pacman->moveRight();
            scene->update();
        }
    }
}

void MainWindow::gameLoop(void)
{
    /* Update tile position of each actor */
    pacman->updateCurrTile();
    ghostBlue->updateCurrTile();
    ghostRed->updateCurrTile();
    ghostGreen->updateCurrTile();
    ghostYellow->updateCurrTile();

    /* Update pacman fields */
    ui->label_lifes_num->setText(QString::number(pacman->getNumOfLifes()));
    ui->label_points->setText(QString::number(pacman->getPoints()));


    if(pacman->getCurrTile() == ghostBlue->getCurrTile())
    {
        qDebug() << "DEAD";
        pacman->setNumOfLifes(pacman->getNumOfLifes() - 1);
        pacman->setLocation(20, 20);
    }

    if( (tileArr[pacman->getCurrTile()].getTileType() == 17) && (lastTile != pacman->getCurrTile()) )
    {
        pacman->setPoints(pacman->getPoints() + 1);
    }

    qDebug() << ghostRed->getCurrTile();
    qDebug() << pacman->getCurrTile();

    if(ghostRed->getYPos() == pacman->getYPos())
    {
        if(ghostRed->getXPos() > pacman->getXPos())
        {
            ghostRed->setDirection(1);
        }
        else
        {
            ghostRed->setDirection(2);
        }
    }
    else if(ghostRed->getXPos() == pacman->getXPos())
    {
        if(ghostRed->getYPos() > pacman->getYPos())
        {
            ghostRed->setDirection(3);
        }
        else
        {
            ghostRed->setDirection(4);
        }
    }

    switch(ghostRed->getDirection())
    {
        case 1:
            ghostRed->moveLeft();
            break;
        case 2:
            ghostRed->moveRight();
            break;
        case 3:
            ghostRed->moveUp();
            break;
        case 4:
            ghostRed->moveDown();
            break;
    }

    /* Save last position of pacman */
    lastTile = pacman->getCurrTile();
    lastTileType = tileArr[pacman->getCurrTile()].getTileType();

}
