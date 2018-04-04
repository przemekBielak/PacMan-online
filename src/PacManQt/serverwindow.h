#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include "globaltypes.h"

#include <QWidget>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class serverWindow;
}

/**
 * serverWindow class is responsible listening to any incoming connection.
 * Class is sending/receiving data over tcp protocol.
 */
class serverWindow : public QWidget
{
    Q_OBJECT

public:
    explicit serverWindow(QWidget *parent = 0);
    ~serverWindow();
    void sendData(QByteArray string);

    QByteArray getReceivedData() const;

signals:
    void setActiveWidget(int activeWidget);

private slots:
    void on_pushButton_host_clicked();
    void newConnection();
    void readyRead();

private:
    Ui::serverWindow *ui;
    /**
     * @var QTcpServer *tcpServer
     * @brief Server instance.
     */
    QTcpServer *tcpServer;
    /**
     * @var QTcpSocket *serverSocket
     * @brief Server socket - used to send data.
     */
    QTcpSocket *serverSocket;
    /**
     * @var QByteArray receivedData
     * @brief Used to store received data from client.
     */
    QByteArray receivedData;
};

#endif // SERVERWINDOW_H
