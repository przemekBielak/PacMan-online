#include "mainwindow.h"
#include <QApplication>

/** @file main.cpp */

/**
 * @fn int main(int argc, char *argv[])
 * @brief main function.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
