#include "mainwindow.h"
#include "ui_mainwindow.h"

/** @file mainwindow.cpp */

/**
 * @fn MainWindow::MainWindow(QWidget *parent)
 * @brief MainWindow class constructor.
 * @details Initializes all game widget windows, setsup stackedWidget view.
 * @param QWidget *parent
 * @retval void
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Create all game view widgets */
    gameOptionsWidget = new gameOptions;
    gameWindowWidget = new gameWindow;
    serverWindowWidget = new serverWindow;
    clientwindowWidget = new clientwindow;

    /* Pass client/server object to gameWindow class */
    gameWindowWidget->setGameServer(serverWindowWidget);
    gameWindowWidget->setGameClient(clientwindowWidget);

    /* Setup stackedWidget, add all widgets */
    QStackedWidget *stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(gameOptionsWidget);
    stackedWidget->addWidget(gameWindowWidget);
    stackedWidget->addWidget(serverWindowWidget);
    stackedWidget->addWidget(clientwindowWidget);

    /* Set game option widget as the default view */
    setCentralWidget(stackedWidget);
    stackedWidget->setCurrentIndex(GAME_OPTION_WIDGET);

    /* connect signals/slots for window change */
    connect(gameOptionsWidget, SIGNAL(setActiveWidget(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    connect(clientwindowWidget, SIGNAL(setActiveWidget(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    connect(serverWindowWidget, SIGNAL(setActiveWidget(int)), stackedWidget, SLOT(setCurrentIndex(int)));

    /* execute code when window changed */
    connect(stackedWidget, SIGNAL(currentChanged(int)), this, SLOT(stackedWidgetChanged(int)));
}

/**
 * @fn MainWindow::~MainWindow()
 * @brief MainWindow class deconstructor
 * @param void
 * @return void
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @fn void MainWindow::stackedWidgetChanged(int widgetNum)
 * @brief Slot starts game when player selected server or client role.
 * @param int widgetNum
 * @return void
 */
void MainWindow::stackedWidgetChanged(int widgetNum)
{
    if (widgetNum == GAME_WIDGET)
    {
        gameWindowWidget->setConnectionRole(gameOptionsWidget->getConnectionRole());
        qDebug() << gameWindowWidget->getConnectionRole();
        gameWindowWidget->startGame();
    }
}



