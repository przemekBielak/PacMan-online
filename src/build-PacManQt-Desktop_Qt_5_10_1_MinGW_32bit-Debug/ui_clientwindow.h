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
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_Status;
    QLabel *label_StatusText;

    void setupUi(QWidget *clientwindow)
    {
        if (clientwindow->objectName().isEmpty())
            clientwindow->setObjectName(QStringLiteral("clientwindow"));
        clientwindow->resize(400, 300);
        widget = new QWidget(clientwindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(120, 100, 135, 108));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

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
        label->setText(QApplication::translate("clientwindow", "Join a Game", nullptr));
        pushButton->setText(QApplication::translate("clientwindow", "Join", nullptr));
        label_Status->setText(QApplication::translate("clientwindow", "Status", nullptr));
        label_StatusText->setText(QApplication::translate("clientwindow", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientwindow: public Ui_clientwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
