#include "clientwindow.h"
#include "ui_clientwindow.h"

clientwindow::clientwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientwindow)
{
    ui->setupUi(this);
    ui->label_StatusText->setText("Not Connected");

    tcpClient = new QTcpSocket();
    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(tcpClient, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

clientwindow::~clientwindow()
{
    delete ui;
}

void clientwindow::on_pushButton_Join_clicked()
{
    connectToServer();
}

void clientwindow::sendData(QByteArray string)
{
    tcpClient->write(string);
    tcpClient->flush();
}

void clientwindow::readyRead()
{
    receivedData = tcpClient->readAll();
    qDebug() << "Received data " << receivedData;

    if(receivedData == TCP_CMD_START_GAME)
    {
       emit setActiveWidget(GAME_WIDGET);
    }

}

void clientwindow::disconnected()
{

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

QByteArray clientwindow::getReceivedData() const
{
    return receivedData;
}

