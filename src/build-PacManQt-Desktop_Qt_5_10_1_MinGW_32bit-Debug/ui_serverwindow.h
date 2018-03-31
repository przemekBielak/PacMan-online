/********************************************************************************
** Form generated from reading UI file 'serverwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
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
    QLabel *label_Host;
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
        widget->setGeometry(QRect(41, 51, 231, 141));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_Host = new QLabel(widget);
        label_Host->setObjectName(QStringLiteral("label_Host"));

        verticalLayout->addWidget(label_Host);

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
        serverWindow->setWindowTitle(QApplication::translate("serverWindow", "Form", nullptr));
        label_Host->setText(QApplication::translate("serverWindow", "The server is running on port 1234", nullptr));
        pushButton_host->setText(QApplication::translate("serverWindow", "Host", nullptr));
        label_Status->setText(QApplication::translate("serverWindow", "Status", nullptr));
        label_StatusText->setText(QApplication::translate("serverWindow", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serverWindow: public Ui_serverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
