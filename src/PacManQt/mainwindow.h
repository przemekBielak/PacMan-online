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

/**
 * MainWindow class is responsible for switching between active windows.
 */
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
    /**
     * @var QStackedWidget *stackedWidget
     * @brief stackedWidget connects and enables to switch between all window widgets.
     */
    QStackedWidget *stackedWidget;
    /**
     * @var gameOptions *gameOptionsWidget
     * @brief gameOptions class object connected to stackedWidget.
     */
    gameOptions *gameOptionsWidget;
    /**
     * @var gameWindow *gameWindowWidget
     * @brief gameWindow class object connected to stackedWidget.
     */
    gameWindow *gameWindowWidget;
    /**
     * @var serverWindow *serverWindowWidget
     * @brief serverWindow class object connected to stackedWidget.
     */
    serverWindow *serverWindowWidget;
    /**
     * @var clientwindow *clientwindowWidget
     * @brief clientwindow class object connected to stackedWidget.
     */
    clientwindow *clientwindowWidget;

};



#endif // MAINWINDOW_H
