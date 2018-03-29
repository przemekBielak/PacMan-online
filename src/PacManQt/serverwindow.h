#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QWidget>

namespace Ui {
class serverWindow;
}

class serverWindow : public QWidget
{
    Q_OBJECT

public:
    explicit serverWindow(QWidget *parent = 0);
    ~serverWindow();

private:
    Ui::serverWindow *ui;
};

#endif // SERVERWINDOW_H
