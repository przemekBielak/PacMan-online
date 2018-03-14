#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tile.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

//    sceneBound = new QRectF(0, 0, 600, 600);
    scene->setSceneRect(0, 0, 600, 600);

    tileWidth = 20;
    tileHeight = 20;
    screenWidth = scene->sceneRect().width();
    screenHeight = scene->sceneRect().height();
    qDebug() << screenHeight;
    qDebug() << screenWidth;

    int mapArrWidth = screenWidth/tileWidth;
    int mapArrHeight = screenHeight/tileHeight;

    int mapArr[mapArrWidth * mapArrHeight];

    for(int i = 0; i < mapArrWidth * mapArrHeight; i++)
    {
        mapArr[i] = 1;
    }


    QPixmap *dotPixmap = new QPixmap(":/Images/rosekane_4.png");

    Tile superDot;
    superDot.setPixmap(dotPixmap);
    superDot.setXPos(100);
    superDot.setYPos(100);
    superDot.setLocation();

    Tile superDot2;
    superDot2.setPixmap(dotPixmap);
    superDot2.setXPos(105);
    superDot2.setYPos(105);
    superDot2.setLocation();

    Tile superDot3;
    superDot3.setPixmap(dotPixmap);
    superDot3.setXPos(200);
    superDot3.setYPos(200);
    superDot3.setLocation();


    scene->addItem(superDot.getPixmapItem());
    scene->addItem(superDot2.getPixmapItem());
    scene->addItem(superDot3.getPixmapItem());

//    superDot.pixmapItem->setPos(0, 0);

}

MainWindow::~MainWindow()
{
    delete ui;


}
