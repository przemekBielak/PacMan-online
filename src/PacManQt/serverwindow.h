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

class serverWindow : public QWidget
{
    Q_OBJECT

public:
    explicit serverWindow(QWidget *parent = 0);
    ~serverWindow();

signals:
    void setActiveWidget(int activeWidget);

private slots:
    void on_pushButton_host_clicked();
    void newConnection();

private:
    Ui::serverWindow *ui;
    QTcpServer *tcpServer;

};

#endif // SERVERWINDOW_H
