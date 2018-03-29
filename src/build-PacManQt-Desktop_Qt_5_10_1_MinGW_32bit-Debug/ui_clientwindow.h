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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientwindow
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *clientwindow)
    {
        if (clientwindow->objectName().isEmpty())
            clientwindow->setObjectName(QStringLiteral("clientwindow"));
        clientwindow->resize(400, 300);
        label = new QLabel(clientwindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 110, 81, 21));
        pushButton = new QPushButton(clientwindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 190, 75, 23));

        retranslateUi(clientwindow);

        QMetaObject::connectSlotsByName(clientwindow);
    } // setupUi

    void retranslateUi(QWidget *clientwindow)
    {
        clientwindow->setWindowTitle(QApplication::translate("clientwindow", "Form", nullptr));
        label->setText(QApplication::translate("clientwindow", "Client Widget", nullptr));
        pushButton->setText(QApplication::translate("clientwindow", "Start Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientwindow: public Ui_clientwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
