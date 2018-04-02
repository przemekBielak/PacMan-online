#include "clientwindow.h"
#include "ui_clientwindow.h"

clientwindow::clientwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientwindow)
{
    ui->setupUi(this);
    ui->label_StatusText->setText("Not Connected");
    tcpClient = new QTcpSocket(this);
    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

clientwindow::~clientwindow()
{
    delete ui;
}


void clientwindow::on_pushButton_Join_clicked()
{
    connectToServer();
}

void clientwindow::readyRead()
{
    QByteArray receivedData = tcpClient->readAll();
    qDebug() << "Received data " << receivedData;

    if(receivedData == TCP_CMD_START_GAME)
    {
       emit setActiveWidget(GAME_WIDGET);
    }
//    else if(receivedData == "gameloop")
//    {
//        qDebug() << "Received from gameloop";
//    }
}


void clientwindow::connectToServer()
{
    ui->label_StatusText->setText("Connecting");

    QString hostAddress = ui->lineEdit_HostAddressText->text();
    qint16 hostPort = (ui->lineEdit_HostPortText->text()).toInt();
    tcpClient->connectToHost("127.0.0.1", 1234);

    if(tcpClient->waitForConnected(3000))
    {
        qDebug() << "Client Connected!";
    }
    else
    {
        qDebug() << "Client Not connected!";
        ui->label_StatusText->setText("Not Connected");
    }

}
