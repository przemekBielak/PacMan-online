#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Create all game view widgets */
    gameWindow *gameWindowWidget = new gameWindow;
    gameOptions *gameOptionsWidget = new gameOptions;

    QStackedWidget *stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(gameOptionsWidget);
    stackedWidget->addWidget(gameWindowWidget);

    setCentralWidget(stackedWidget);
    stackedWidget->setCurrentIndex(0);


}


MainWindow::~MainWindow()
{
    delete ui;
}
