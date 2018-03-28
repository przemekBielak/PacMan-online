#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameoptions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Create all game view widgets */
    gameOptions *gameOptionsWidget = new gameOptions;
    gameWindow *gameWindowWidget = new gameWindow;

    QStackedWidget *stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(gameOptionsWidget);
    stackedWidget->addWidget(gameWindowWidget);

    setCentralWidget(stackedWidget);
    stackedWidget->setCurrentIndex(GAME_OPTION_WIDGET);

    connect(gameOptionsWidget, SIGNAL(setActiveWidget(int)), stackedWidget, SLOT(setCurrentIndex(int)));

}


MainWindow::~MainWindow()
{
    delete ui;
}



