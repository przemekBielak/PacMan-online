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


void clientwindow::on_pushButton_Join_clicked()
{
    connect();
}

void clientwindow::connect()
{
    qDebug() << "Connecting...";
    tcpClient = new QTcpSocket(this);
    tcpClient->connectToHost("127.0.0.1", 1234);

    if(tcpClient->waitForConnected(3000))
    {
        qDebug() << "Connected!";
        tcpClient->close();
        emit setActiveWidget(GAME_WIDGET);
    }
    else
    {
        qDebug() << "Not connected!";
    }

}
