#include "serverwindow.h"
#include "ui_serverwindow.h"

serverWindow::serverWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serverWindow)
{
    ui->setupUi(this);
    ui->label_StatusText->setText("Not Connected");

}

serverWindow::~serverWindow()
{
    delete ui;
}

void serverWindow::on_pushButton_host_clicked()
{
    tcpServer = new QTcpServer(this);

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!tcpServer->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

void serverWindow::newConnection()
{
    QTcpSocket *socket = tcpServer->nextPendingConnection();
    socket->write("hello new client!\r\n");
    socket->flush();
    socket->close();
    qDebug() << "New connection!";


    /* When conenction established, start the game */
    emit setActiveWidget(GAME_WIDGET);
    ui->label_StatusText->setText("Connected");
}



