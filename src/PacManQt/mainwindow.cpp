#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    gameWindowWidget->setGameServer(serverWindowWidget);

    QStackedWidget *stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(gameOptionsWidget);
    stackedWidget->addWidget(gameWindowWidget);
    stackedWidget->addWidget(serverWindowWidget);
    stackedWidget->addWidget(clientwindowWidget);

    setCentralWidget(stackedWidget);
    stackedWidget->setCurrentIndex(GAME_OPTION_WIDGET);


    /* connect signals/slots for window change */
    connect(gameOptionsWidget, SIGNAL(setActiveWidget(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    connect(clientwindowWidget, SIGNAL(setActiveWidget(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    connect(serverWindowWidget, SIGNAL(setActiveWidget(int)), stackedWidget, SLOT(setCurrentIndex(int)));

    /* execute code when window changed */
    connect(stackedWidget, SIGNAL(currentChanged(int)), this, SLOT(stackedWidgetChanged(int)));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::stackedWidgetChanged(int widgetNum)
{
    qDebug() << widgetNum;

    if (widgetNum == GAME_WIDGET)
    {
        gameWindowWidget->startGame();
    }
    else if(widgetNum == SERVER_WIDGET)
    {
//        serverWindowWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
//        stackedWidget->adjustSize();
    }
}



