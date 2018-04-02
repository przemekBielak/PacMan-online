#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include "globaltypes.h"

#include <QWidget>
#include <QTcpSocket>
#include <QDebug>


namespace Ui {
class clientwindow;
}

class clientwindow : public QWidget
{
    Q_OBJECT

public:
    explicit clientwindow(QWidget *parent = 0);
    ~clientwindow();
    void sendData(QByteArray string);

signals:
    void setActiveWidget(int activeWidget);

private slots:
    void on_pushButton_Join_clicked();

public slots:
    void readyRead();

private:
    void connectToServer();

    Ui::clientwindow *ui;
    QTcpSocket *tcpClient;
};

#endif // CLIENTWINDOW_H
