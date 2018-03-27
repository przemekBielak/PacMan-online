/********************************************************************************
** Form generated from reading UI file 'gameoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOPTIONS_H
#define UI_GAMEOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameOptions
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *gameOptions)
    {
        if (gameOptions->objectName().isEmpty())
            gameOptions->setObjectName(QStringLiteral("gameOptions"));
        gameOptions->resize(295, 194);
        widget = new QWidget(gameOptions);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(62, 72, 158, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(gameOptions);

        QMetaObject::connectSlotsByName(gameOptions);
    } // setupUi

    void retranslateUi(QWidget *gameOptions)
    {
        gameOptions->setWindowTitle(QApplication::translate("gameOptions", "Form", nullptr));
        pushButton_2->setText(QApplication::translate("gameOptions", "Client", nullptr));
        pushButton->setText(QApplication::translate("gameOptions", "Server", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameOptions: public Ui_gameOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOPTIONS_H
