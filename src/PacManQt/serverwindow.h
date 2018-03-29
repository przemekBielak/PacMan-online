#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QWidget>
#include "globaltypes.h"

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
    void on_pushButton_clicked();

private:
    Ui::serverWindow *ui;
};

#endif // SERVERWINDOW_H
