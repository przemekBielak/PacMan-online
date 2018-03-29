#include "serverwindow.h"
#include "ui_serverwindow.h"

serverWindow::serverWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serverWindow)
{
    ui->setupUi(this);
}

serverWindow::~serverWindow()
{
    delete ui;
}

void serverWindow::on_pushButton_clicked()
{
    emit setActiveWidget(GAME_WIDGET);
}
