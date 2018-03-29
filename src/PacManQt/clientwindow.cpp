#include "clientwindow.h"
#include "ui_clientwindow.h"

clientwindow::clientwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientwindow)
{
    ui->setupUi(this);
}

clientwindow::~clientwindow()
{
    delete ui;
}

void clientwindow::on_pushButton_clicked()
{
    emit setActiveWidget(GAME_WIDGET);
}
