/********************************************************************************
** Form generated from reading UI file 'serverwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWINDOW_H
#define UI_SERVERWINDOW_H

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

class Ui_serverWindow
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_HostPort;
    QLineEdit *lineEdit_HostPortEdit;
    QPushButton *pushButton_host;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Status;
    QSpacerItem *horizontalSpacer;
    QLabel *label_StatusText;

    void setupUi(QWidget *serverWindow)
    {
        if (serverWindow->objectName().isEmpty())
            serverWindow->setObjectName(QStringLiteral("serverWindow"));
        serverWindow->resize(308, 233);
        widget = new QWidget(serverWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 70, 188, 81));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_HostPort = new QLabel(widget);
        label_HostPort->setObjectName(QStringLiteral("label_HostPort"));

        horizontalLayout_2->addWidget(label_HostPort);

        lineEdit_HostPortEdit = new QLineEdit(widget);
        lineEdit_HostPortEdit->setObjectName(QStringLiteral("lineEdit_HostPortEdit"));

        horizontalLayout_2->addWidget(lineEdit_HostPortEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_host = new QPushButton(widget);
        pushButton_host->setObjectName(QStringLiteral("pushButton_host"));

        verticalLayout->addWidget(pushButton_host);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_Status = new QLabel(widget);
        label_Status->setObjectName(QStringLiteral("label_Status"));

        horizontalLayout->addWidget(label_Status);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_StatusText = new QLabel(widget);
        label_StatusText->setObjectName(QStringLiteral("label_StatusText"));

        horizontalLayout->addWidget(label_StatusText);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(serverWindow);

        QMetaObject::connectSlotsByName(serverWindow);
    } // setupUi

    void retranslateUi(QWidget *serverWindow)
    {
        serverWindow->setWindowTitle(QApplication::translate("serverWindow", "Form", 0));
        label_HostPort->setText(QApplication::translate("serverWindow", "Host Port", 0));
        pushButton_host->setText(QApplication::translate("serverWindow", "Host", 0));
        label_Status->setText(QApplication::translate("serverWindow", "Status", 0));
        label_StatusText->setText(QApplication::translate("serverWindow", "Status", 0));
    } // retranslateUi

};

namespace Ui {
    class serverWindow: public Ui_serverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
