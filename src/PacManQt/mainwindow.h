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
#include <QStackedWidget>
#include <QComboBox>

#include "gameoptions.h"
#include "gamewindow.h"
#include "globaltypes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static QStackedWidget *stackedWidget;


private:
    Ui::MainWindow *ui;

};



#endif // MAINWINDOW_H
