#ifndef GAMEOPTIONS_H
#define GAMEOPTIONS_H

#include <QWidget>
#include "globaltypes.h"


namespace Ui {
class gameOptions;
}

/**
 * gameOptions class creates a welcome screen, where user can select
 * to start a game in server or client mode.
 */
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
    /**
     * @var connectionRoleType connectionRole
     * @brief Specifies if game was started as a server or as a client.
     */
    connectionRoleType connectionRole;
};

#endif // GAMEOPTIONS_H
