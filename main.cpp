/** Emily Wang
 *  1/26/16
 *  @brief This project contains the overall user interface for the game Massive.
 *  Eat food and gain mass! Avoid getting hit by enemies. If you lose too much mass, you lose the game.
 *  Shoot enemies, but cautiously, as your mass will decrease. Try to get the highest score you can!
 */

/** @file main.cpp
 *  @brief Creates the main window and runs the program
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
