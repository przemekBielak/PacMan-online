#include "serverwindow.h"
#include "ui_serverwindow.h"

serverWindow::serverWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serverWindow)
{
    ui->setupUi(this);
    ui->label_StatusText->setText("Not Connected");

    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

serverWindow::~serverWindow()
{
    delete ui;
}

void serverWindow::sendData(QByteArray string)
{
    serverSocket->write(string);
    serverSocket->flush();
}

void serverWindow::on_pushButton_host_clicked()
{
    qint16 hostPort = ui->lineEdit_HostPortEdit->text().toInt();

    if(!tcpServer->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
        ui->label_StatusText->setText("Waiting for connection...");
    }
}

void serverWindow::newConnection()
{
    serverSocket = tcpServer->nextPendingConnection();
    connect(serverSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    sendData(TCP_CMD_START_GAME);

    /* When conenction established, start the game */
    emit setActiveWidget(GAME_WIDGET);
    ui->label_StatusText->setText("Connected");
}

void serverWindow::readyRead()
{
    receivedData = serverSocket->readAll();
    qDebug() << "Received data " << receivedData;
}

QByteArray serverWindow::getReceivedData() const
{
    return receivedData;
}



