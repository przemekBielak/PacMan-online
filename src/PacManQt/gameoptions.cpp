#include "gameoptions.h"
#include "ui_gameoptions.h"

gameOptions::gameOptions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameOptions)
{
    ui->setupUi(this);
}

gameOptions::~gameOptions()
{
    delete ui;
}
