#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include "globaltypes.h"

#include <QWidget>
#include <QTcpSocket>
#include <QDebug>


namespace Ui {
class clientwindow;
}

/**
 * clientwindow class is responsible for estabilishing connection with server.
 * Class is sending/receiving data over tcp protocol.
 */
class clientwindow : public QWidget
{
    Q_OBJECT

public:
    explicit clientwindow(QWidget *parent = 0);
    ~clientwindow();
    void sendData(QByteArray string);

    QByteArray getReceivedData() const;

signals:
    void setActiveWidget(int activeWidget);

private slots:
    void on_pushButton_Join_clicked();

public slots:
    void readyRead();

private:
    void connectToServer();

    Ui::clientwindow *ui;
    /**
     * @var QTcpSocket *tcpClient
     * @brief Client socket - used to send data.
     */
    QTcpSocket *tcpClient;
    /**
     * @var QByteArray receivedData
     * @brief Used to store received data from client.
     */
    QByteArray receivedData;
};

#endif // CLIENTWINDOW_H
