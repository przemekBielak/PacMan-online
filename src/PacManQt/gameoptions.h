#ifndef GAMEOPTIONS_H
#define GAMEOPTIONS_H

#include <QWidget>
#include "globaltypes.h"


namespace Ui {
class gameOptions;
}

class gameOptions : public QWidget
{
    Q_OBJECT

public:
    explicit gameOptions(QWidget *parent = 0);
    ~gameOptions();

    connectionRoleType getConnectionRole() const;

signals:
    void setActiveWidget(int activeWidget);


private slots:
    void on_pushButtonClient_clicked();

    void on_pushButtonServer_clicked();

private:
    Ui::gameOptions *ui;
    connectionRoleType connectionRole;
};

#endif // GAMEOPTIONS_H
