/** @file myplayer.cpp
 *  @brief Implementation for MyPlayer class
 *  Implements functions for the user's character
 */

#include "MyPlayer.h"
#include "Mass.h"
#include <QGraphicsScene>
#include "Enemy.h"
#include "enemymass.h"
#include "Food.h"

extern GameBoard* gameboard;
/**
 * @brief sets keyboard controls in order to move the player
 */
void MyPlayer::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        //if player is not past left boundaries of screen
        if (pos().x() > 0)
            //move to left
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right) {
        //if player is not past right boundaries of screen
        if (pos().x() + boundingRect().width() < 900)
            //move to right
            setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up) {
        //if player is not past top boundaries of screen
        if (pos().y() > 0)
            //move up
            setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down) {
        //if player is not past bottom boundaries of screen
        if (pos().y() + boundingRect().height() < 700)
            //move down
            setPos(x(), y()+10);
    }
    //creates mass to shoot if space is pressed
    else if (event->key() == Qt::Key_Space) {
        Mass * mass = new Mass();
        mass->setPos(x(),y());
        scene()->addItem(mass);
        //decrease score since lost mass
        gameboard->displayscore->subtract();

        //decrease user's size by decreasing scale relative to current size
        this->setScale(this->scale() * 0.7);

        //if user shoots mass and score becomes less than zero
        if (gameboard->displayscore->score < 0)
            gameboard->gameOver();
    }
}

/**
 * @brief Creates enemies using a timer
 */
void MyPlayer::create() {
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}

/**
 * @brief Creates food to add to gameboard
 */
void MyPlayer::makefood() {
    Food * food = new Food();
    scene()->addItem(food);
}
