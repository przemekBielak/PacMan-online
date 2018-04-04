#include "serverwindow.h"
#include "ui_serverwindow.h"

/**
 * @fn serverWindow(QWidget *parent = 0)
 * @brief serverWindow class constructor.
 * @details Creates new tcpServer.
 * @param QWidget *parent
 * @retval void
 */
serverWindow::serverWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serverWindow)
{
    ui->setupUi(this);
    ui->label_StatusText->setText("Not Connected");

    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

/**
 * @fn ~serverWindow()
 * @brief serverWindow class deconstructor
 * @param void
 * @return void
 */
serverWindow::~serverWindow()
{
    delete ui;
}

/**
 * @fn void sendData(QByteArray string)
 * @brief sends data from serverSocket
 * @param QByteArray string
 * @return void
 */
void serverWindow::sendData(QByteArray string)
{
    serverSocket->write(string);
    serverSocket->flush();
}

/**
 * @fn void on_pushButton_host_clicked()
 * @brief Slot starts server.
 * @details Server is listening for any incomming connection.
 * @param void
 * @return void
 */
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

/**
 * @fn void newConnection()
 * @brief Slot starts connection with the newest incoming request.
 * @details Server sends TCP_CMD_START_GAME to Client - as a game start request.
 * @param void
 * @return void
 */
void serverWindow::newConnection()
{
    serverSocket = tcpServer->nextPendingConnection();
    connect(serverSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    sendData(TCP_CMD_START_GAME);

    /* When conenction established, start the game */
    emit setActiveWidget(GAME_WIDGET);
    ui->label_StatusText->setText("Connected");
}

/**
 * @fn void readyRead()
 * @brief Slot stores all received data from client to receivedData
 * @param void
 * @return void
 */
void serverWindow::readyRead()
{
    receivedData = serverSocket->readAll();
    qDebug() << "Received data " << receivedData;
}

/**
 * @fn QByteArray getReceivedData() const
 * @brief receivedData getter.
 */
QByteArray serverWindow::getReceivedData() const
{
    return receivedData;
}



