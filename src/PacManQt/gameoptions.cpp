#include "gameoptions.h"
#include "ui_gameoptions.h"
#include <QDebug>

/**
 * @fn explicit gameOptions(QWidget *parent = 0)
 * @brief gameOptions class constructor.
 * @details Sets up windows widget ui.
 * @param QWidget *parent
 * @return void
 */
gameOptions::gameOptions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameOptions)
{
    ui->setupUi(this);
}

/**
 * @fn ~gameOptions()
 * @brief gameOptions class deconstructor.
 * @param void
 * @return void
 */
gameOptions::~gameOptions()
{
    delete ui;
}

/**
 * @fn void on_pushButtonClient_clicked()
 * @brief This slot, when called emits signal setActiveWidget(CLIENT_WIDGET)
 * and sets connectionRole as CLIENT_ROLE.
 * @param void
 * @return void
 */
void gameOptions::on_pushButtonClient_clicked()
{
    emit setActiveWidget(CLIENT_WIDGET);
    connectionRole = CLIENT_ROLE;
}

/**
 * @fn void on_pushButtonServer_clicked()
 * @brief This slot, when called emits signal setActiveWidget(SERVER_WIDGET)
 * and sets connectionRole as SERVER_ROLE.
 * @param void
 * @return void
 */
void gameOptions::on_pushButtonServer_clicked()
{
    emit setActiveWidget(SERVER_WIDGET);
    connectionRole = SERVER_ROLE;
}

/**
 * @fn connectionRoleType getConnectionRole() const
 * @brief connectionRole getter.
 */
connectionRoleType gameOptions::getConnectionRole() const
{
    return connectionRole;
}

