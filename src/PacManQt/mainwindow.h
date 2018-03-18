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

#include "tile.h"
#include "actor.h"
#include "pacman.h"
#include "ghost.h"

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
    int mapArrWidth;
    int mapArrHeight;

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *event);
    Ghost *ghostRed;
    Ghost *ghostYellow;
    Ghost *ghostGreen;
    Ghost *ghostBlue;
    Pacman *pacman;

protected:
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
