#include "clientwindow.h"
#include "ui_clientwindow.h"

clientwindow::clientwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientwindow)
{
    ui->setupUi(this);
    ui->label_StatusText->setText("Not Connected");
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
    ui->label_StatusText->setText("Connecting");
    tcpClient = new QTcpSocket(this);

    QString hostAddress = ui->lineEdit_HostAddressText->text();
    qint16 hostPort = (ui->lineEdit_HostPortText->text()).toInt();
    tcpClient->connectToHost(hostAddress, hostPort);

    if(tcpClient->waitForConnected(3000))
    {
        qDebug() << "Connected!";
        tcpClient->close();
        emit setActiveWidget(GAME_WIDGET);
    }
    else
    {
        qDebug() << "Not connected!";
        ui->label_StatusText->setText("Not Connected");
    }

}
