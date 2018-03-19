/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLabel *label_lifes_text;
    QLabel *label_lifes_num;
    QLabel *label_points_text;
    QLabel *label_points;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(778, 712);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 20, 620, 620));
        label_lifes_text = new QLabel(centralWidget);
        label_lifes_text->setObjectName(QStringLiteral("label_lifes_text"));
        label_lifes_text->setGeometry(QRect(650, 70, 26, 16));
        label_lifes_num = new QLabel(centralWidget);
        label_lifes_num->setObjectName(QStringLiteral("label_lifes_num"));
        label_lifes_num->setGeometry(QRect(700, 70, 47, 16));
        label_points_text = new QLabel(centralWidget);
        label_points_text->setObjectName(QStringLiteral("label_points_text"));
        label_points_text->setGeometry(QRect(650, 90, 47, 16));
        label_points = new QLabel(centralWidget);
        label_points->setObjectName(QStringLiteral("label_points"));
        label_points->setGeometry(QRect(700, 90, 47, 16));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_lifes_text->setText(QApplication::translate("MainWindow", "Lifes:", nullptr));
        label_lifes_num->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_points_text->setText(QApplication::translate("MainWindow", "Points:", nullptr));
        label_points->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
