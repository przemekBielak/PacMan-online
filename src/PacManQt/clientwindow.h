#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QWidget>
#include "globaltypes.h"

namespace Ui {
class clientwindow;
}

class clientwindow : public QWidget
{
    Q_OBJECT

public:
    explicit clientwindow(QWidget *parent = 0);
    ~clientwindow();

signals:
    void setActiveWidget(int activeWidget);

private slots:
    void on_pushButton_clicked();

private:
    Ui::clientwindow *ui;
};

#endif // CLIENTWINDOW_H
