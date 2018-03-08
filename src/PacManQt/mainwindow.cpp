#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);
    QPen blackPen(Qt::black);
    blackPen.setWidth(6);

//    ellipse = scene->addEllipse(10, 10, 100, 100, blackPen, blueBrush);
    //rectangle = scene->addRect(-100, -100, 50, 50, blackPen, greenBrush);

    image = new QImage("rosekane_0.png");
    item = new QGraphicsPixmapItem();
//    item->setPixmap(QPixmap::fromImage(*image));


    item->setVisible(true);
    item = scene->addPixmap(QPixmap::fromImage(*image));
}

MainWindow::~MainWindow()
{
    delete ui;
}
