/** @file gameboard.h
 *  @brief declaration for member functions for the game board
 */

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "mainwindow.h"

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "MyPlayer.h"
#include "score.h"

#include "Food.h"
#include "gameover.h"

#include <QMediaPlayer>

namespace Ui {
class GameBoard;
}

class GameBoard : public QDialog
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = 0);
    explicit GameBoard(int charchoice, QWidget *parent = 0);
    QGraphicsScene *scene;
    Score * displayscore;
    void gameOver();
    GameOver* gameover;

    ~GameBoard();

private:
    Ui::GameBoard *ui;
    QGraphicsView *view;
    QTimer * timer;
    QTimer * foodtimer;
    QMediaPlayer * song;

//    MainWindow& window;

};

#endif // GAMEBOARD_H
