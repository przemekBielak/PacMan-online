/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientwindow
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_JoinGame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_HostAddress;
    QLineEdit *lineEdit_HostAddressText;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_HostPort;
    QLineEdit *lineEdit_HostPortText;
    QPushButton *pushButton_Join;
    QLabel *label_Status;
    QLabel *label_StatusText;

    void setupUi(QWidget *clientwindow)
    {
        if (clientwindow->objectName().isEmpty())
            clientwindow->setObjectName(QStringLiteral("clientwindow"));
        clientwindow->resize(400, 300);
        widget = new QWidget(clientwindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 101, 207, 138));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_JoinGame = new QLabel(widget);
        label_JoinGame->setObjectName(QStringLiteral("label_JoinGame"));

        verticalLayout->addWidget(label_JoinGame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_HostAddress = new QLabel(widget);
        label_HostAddress->setObjectName(QStringLiteral("label_HostAddress"));

        horizontalLayout->addWidget(label_HostAddress);

        lineEdit_HostAddressText = new QLineEdit(widget);
        lineEdit_HostAddressText->setObjectName(QStringLiteral("lineEdit_HostAddressText"));

        horizontalLayout->addWidget(lineEdit_HostAddressText);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_HostPort = new QLabel(widget);
        label_HostPort->setObjectName(QStringLiteral("label_HostPort"));

        horizontalLayout_2->addWidget(label_HostPort);

        lineEdit_HostPortText = new QLineEdit(widget);
        lineEdit_HostPortText->setObjectName(QStringLiteral("lineEdit_HostPortText"));

        horizontalLayout_2->addWidget(lineEdit_HostPortText);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_Join = new QPushButton(widget);
        pushButton_Join->setObjectName(QStringLiteral("pushButton_Join"));

        verticalLayout->addWidget(pushButton_Join);

        label_Status = new QLabel(widget);
        label_Status->setObjectName(QStringLiteral("label_Status"));

        verticalLayout->addWidget(label_Status);

        label_StatusText = new QLabel(widget);
        label_StatusText->setObjectName(QStringLiteral("label_StatusText"));

        verticalLayout->addWidget(label_StatusText);


        retranslateUi(clientwindow);

        QMetaObject::connectSlotsByName(clientwindow);
    } // setupUi

    void retranslateUi(QWidget *clientwindow)
    {
        clientwindow->setWindowTitle(QApplication::translate("clientwindow", "Form", nullptr));
        label_JoinGame->setText(QApplication::translate("clientwindow", "Join a Game", nullptr));
        label_HostAddress->setText(QApplication::translate("clientwindow", "Host Address", nullptr));
        label_HostPort->setText(QApplication::translate("clientwindow", "Host Port", nullptr));
        pushButton_Join->setText(QApplication::translate("clientwindow", "Join", nullptr));
        label_Status->setText(QApplication::translate("clientwindow", "Status", nullptr));
        label_StatusText->setText(QApplication::translate("clientwindow", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientwindow: public Ui_clientwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
