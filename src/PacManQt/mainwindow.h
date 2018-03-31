#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>

#include "globaltypes.h"

#include "gameoptions.h"
#include "serverwindow.h"
#include "clientwindow.h"
#include "gamewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void stackedWidgetChanged(int widgetNum);

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;

    gameOptions *gameOptionsWidget;
    gameWindow *gameWindowWidget;
    serverWindow *serverWindowWidget;
    clientwindow *clientwindowWidget;

};



#endif // MAINWINDOW_H
