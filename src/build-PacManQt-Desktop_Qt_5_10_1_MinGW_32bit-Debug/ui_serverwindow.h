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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serverWindow
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *serverWindow)
    {
        if (serverWindow->objectName().isEmpty())
            serverWindow->setObjectName(QStringLiteral("serverWindow"));
        serverWindow->resize(400, 300);
        label = new QLabel(serverWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 110, 91, 31));
        pushButton = new QPushButton(serverWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 190, 75, 23));

        retranslateUi(serverWindow);

        QMetaObject::connectSlotsByName(serverWindow);
    } // setupUi

    void retranslateUi(QWidget *serverWindow)
    {
        serverWindow->setWindowTitle(QApplication::translate("serverWindow", "Form", nullptr));
        label->setText(QApplication::translate("serverWindow", "Server Widget", nullptr));
        pushButton->setText(QApplication::translate("serverWindow", "Start Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serverWindow: public Ui_serverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
