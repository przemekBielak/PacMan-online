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
#include <QTimer>

#include "game_cfg.h"
#include "tile.h"
#include "actor.h"
#include "pacman.h"
#include "ghost.h"

typedef enum directionType_
{
        DIRECTION_LEFT = 0
    ,   DIRECTION_RIGHT
    ,   DIRECTION_UP
    ,   DIRECTION_DOWN
}directionType;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTimer *gameLoopTimer;

public slots:
    void gameLoop(void);

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *event);
    int checkIfMoveIsPossible(Actor *act, directionType direction);

    Ghost *ghostRed;
    Ghost *ghostYellow;
    Ghost *ghostGreen;
    Ghost *ghostBlue;
    Pacman *pacman;

protected:
    QGraphicsScene *scene;
};



#endif // MAINWINDOW_H
