#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "gameoptions.h"
#include "serverwindow.h"
#include "clientwindow.h"
#include "gamewindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Create all game view widgets */
    gameOptions *gameOptionsWidget = new gameOptions;
    gameWindow *gameWindowWidget = new gameWindow;
    serverWindow *serverWindowWidget = new serverWindow;
    clientwindow *clientwindowWidget = new clientwindow;

    QStackedWidget *stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(gameOptionsWidget);
    stackedWidget->addWidget(gameWindowWidget);
    stackedWidget->addWidget(serverWindowWidget);
    stackedWidget->addWidget(clientwindowWidget);

    setCentralWidget(stackedWidget);
    stackedWidget->setCurrentIndex(GAME_OPTION_WIDGET);

    connect(gameOptionsWidget, SIGNAL(setActiveWidget(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    connect(clientwindowWidget, SIGNAL(setActiveWidget(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    connect(serverWindowWidget, SIGNAL(setActiveWidget(int)), stackedWidget, SLOT(setCurrentIndex(int)));

}


MainWindow::~MainWindow()
{
    delete ui;
}



