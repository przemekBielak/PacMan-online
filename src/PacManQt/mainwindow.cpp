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


    Tile superDot;
    scene->addItem(superDot.pixmapItem);
    superDot.setLocation(100, 100);
//    superDot.pixmapItem->setPos(0, 0);

}

MainWindow::~MainWindow()
{
    delete ui;


}
