#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

#include "actor.h"
#include "tile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    int tileWidth;
    int tileHeight;
    int screenWidth;
    int screenHeight;

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *event);
    Actor *ghostRed;
    Actor *ghostYellow;
    Actor *ghostGreen;
    Actor *ghostBlue;
    Actor *pacman;

protected:
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
