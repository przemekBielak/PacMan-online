/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameWindow
{
public:
    QLabel *label_lifes_text_4;
    QLabel *label_points;
    QLabel *label_points_text;
    QLabel *label_lifes_num;
    QLabel *label_points_2;
    QLabel *label_lifes_num_2;
    QLabel *label_points_text_2;
    QLabel *label_game_level_num;
    QLabel *label_lifes_text_2;
    QLabel *label_lifes_text;
    QLabel *label_player1;
    QLabel *label_game_level;
    QGraphicsView *graphicsView;
    QLabel *label_game_level_2;

    void setupUi(QWidget *gameWindow)
    {
        if (gameWindow->objectName().isEmpty())
            gameWindow->setObjectName(QStringLiteral("gameWindow"));
        gameWindow->resize(770, 640);
        label_lifes_text_4 = new QLabel(gameWindow);
        label_lifes_text_4->setObjectName(QStringLiteral("label_lifes_text_4"));
        label_lifes_text_4->setGeometry(QRect(670, 90, 41, 16));
        label_points = new QLabel(gameWindow);
        label_points->setObjectName(QStringLiteral("label_points"));
        label_points->setGeometry(QRect(690, 70, 47, 16));
        label_points_text = new QLabel(gameWindow);
        label_points_text->setObjectName(QStringLiteral("label_points_text"));
        label_points_text->setGeometry(QRect(640, 70, 47, 16));
        label_lifes_num = new QLabel(gameWindow);
        label_lifes_num->setObjectName(QStringLiteral("label_lifes_num"));
        label_lifes_num->setGeometry(QRect(690, 50, 47, 16));
        label_points_2 = new QLabel(gameWindow);
        label_points_2->setObjectName(QStringLiteral("label_points_2"));
        label_points_2->setGeometry(QRect(690, 130, 47, 16));
        label_lifes_num_2 = new QLabel(gameWindow);
        label_lifes_num_2->setObjectName(QStringLiteral("label_lifes_num_2"));
        label_lifes_num_2->setGeometry(QRect(690, 110, 47, 16));
        label_points_text_2 = new QLabel(gameWindow);
        label_points_text_2->setObjectName(QStringLiteral("label_points_text_2"));
        label_points_text_2->setGeometry(QRect(640, 130, 47, 16));
        label_game_level_num = new QLabel(gameWindow);
        label_game_level_num->setObjectName(QStringLiteral("label_game_level_num"));
        label_game_level_num->setGeometry(QRect(710, 160, 47, 16));
        label_lifes_text_2 = new QLabel(gameWindow);
        label_lifes_text_2->setObjectName(QStringLiteral("label_lifes_text_2"));
        label_lifes_text_2->setGeometry(QRect(640, 110, 26, 16));
        label_lifes_text = new QLabel(gameWindow);
        label_lifes_text->setObjectName(QStringLiteral("label_lifes_text"));
        label_lifes_text->setGeometry(QRect(640, 50, 26, 16));
        label_player1 = new QLabel(gameWindow);
        label_player1->setObjectName(QStringLiteral("label_player1"));
        label_player1->setGeometry(QRect(670, 30, 41, 16));
        label_game_level = new QLabel(gameWindow);
        label_game_level->setObjectName(QStringLiteral("label_game_level"));
        label_game_level->setGeometry(QRect(640, 160, 61, 16));
        graphicsView = new QGraphicsView(gameWindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 620, 620));
        label_game_level_2 = new QLabel(gameWindow);
        label_game_level_2->setObjectName(QStringLiteral("label_game_level_2"));
        label_game_level_2->setGeometry(QRect(630, 210, 141, 51));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(true);
        font.setWeight(75);
        label_game_level_2->setFont(font);

        retranslateUi(gameWindow);

        QMetaObject::connectSlotsByName(gameWindow);
    } // setupUi

    void retranslateUi(QWidget *gameWindow)
    {
        gameWindow->setWindowTitle(QApplication::translate("gameWindow", "Form", nullptr));
        label_lifes_text_4->setText(QApplication::translate("gameWindow", "Player 2", nullptr));
        label_points->setText(QApplication::translate("gameWindow", "TextLabel", nullptr));
        label_points_text->setText(QApplication::translate("gameWindow", "Points:", nullptr));
        label_lifes_num->setText(QApplication::translate("gameWindow", "TextLabel", nullptr));
        label_points_2->setText(QApplication::translate("gameWindow", "TextLabel", nullptr));
        label_lifes_num_2->setText(QApplication::translate("gameWindow", "TextLabel", nullptr));
        label_points_text_2->setText(QApplication::translate("gameWindow", "Points:", nullptr));
        label_game_level_num->setText(QApplication::translate("gameWindow", "TextLabel", nullptr));
        label_lifes_text_2->setText(QApplication::translate("gameWindow", "Lifes:", nullptr));
        label_lifes_text->setText(QApplication::translate("gameWindow", "Lifes:", nullptr));
        label_player1->setText(QApplication::translate("gameWindow", "Player 1", nullptr));
        label_game_level->setText(QApplication::translate("gameWindow", "Game Level:", nullptr));
        label_game_level_2->setText(QApplication::translate("gameWindow", "Use WSAD keys to move", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameWindow: public Ui_gameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
