#include "clientwindow.h"
#include "ui_clientwindow.h"

/**
 * @fn clientwindow(QWidget *parent = 0)
 * @brief clientwindow class constructor.
 * @details Creates new tcp client.
 * @param QWidget *parent
 * @retval void
 */
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

/**
 * @fn ~clientwindow()
 * @brief clientwindow class deconstructor
 * @param void
 * @return void
 */
clientwindow::~clientwindow()
{
    delete ui;
}

/**
 * @fn void on_pushButton_Join_clicked()
 * @brief Slot connects client to server.
 * @param void
 * @return void
 */
void clientwindow::on_pushButton_Join_clicked()
{
    connectToServer();
}

/**
 * @fn void sendData(QByteArray string)
 * @brief sends data from serverSocket
 * @param QByteArray string
 * @return void
 */
void clientwindow::sendData(QByteArray string)
{
    tcpClient->write(string);
    tcpClient->flush();
}

/**
 * @fn void readyRead()
 * @brief Slot stores all received data from client to receivedData
 * @param void
 * @return void
 */
void clientwindow::readyRead()
{
    receivedData = tcpClient->readAll();
    qDebug() << "Received data " << receivedData;

    if(receivedData == TCP_CMD_START_GAME)
    {
       emit setActiveWidget(GAME_WIDGET);
    }
}

/**
 * @fn void connectToServer()
 * @brief Find server by ip and port and establish connection.
 * @param void
 * @return void
 */
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

/**
 * @fn QByteArray getReceivedData() const
 * @brief receivedData getter.
 */
QByteArray clientwindow::getReceivedData() const
{
    return receivedData;
}

