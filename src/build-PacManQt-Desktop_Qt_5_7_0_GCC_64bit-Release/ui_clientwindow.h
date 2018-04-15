/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
#include <QtWidgets/QSpacerItem>
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
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Status;
    QSpacerItem *horizontalSpacer;
    QLabel *label_StatusText;

    void setupUi(QWidget *clientwindow)
    {
        if (clientwindow->objectName().isEmpty())
            clientwindow->setObjectName(QStringLiteral("clientwindow"));
        clientwindow->resize(400, 300);
        widget = new QWidget(clientwindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(31, 102, 207, 128));
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

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_Status = new QLabel(widget);
        label_Status->setObjectName(QStringLiteral("label_Status"));

        horizontalLayout_3->addWidget(label_Status);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_StatusText = new QLabel(widget);
        label_StatusText->setObjectName(QStringLiteral("label_StatusText"));

        horizontalLayout_3->addWidget(label_StatusText);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(clientwindow);

        QMetaObject::connectSlotsByName(clientwindow);
    } // setupUi

    void retranslateUi(QWidget *clientwindow)
    {
        clientwindow->setWindowTitle(QApplication::translate("clientwindow", "Form", 0));
        label_JoinGame->setText(QApplication::translate("clientwindow", "Join a Game", 0));
        label_HostAddress->setText(QApplication::translate("clientwindow", "Host Address", 0));
        label_HostPort->setText(QApplication::translate("clientwindow", "Host Port", 0));
        pushButton_Join->setText(QApplication::translate("clientwindow", "Join", 0));
        label_Status->setText(QApplication::translate("clientwindow", "Status", 0));
        label_StatusText->setText(QApplication::translate("clientwindow", "Status", 0));
    } // retranslateUi

};

namespace Ui {
    class clientwindow: public Ui_clientwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
