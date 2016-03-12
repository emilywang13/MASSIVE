/** @file EnemyMass.cpp
 *  @brief Implements functions for the enemy's shooted mass particle
 */

#include "MyPlayer.h"
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "EnemyMass.h"
#include "GameBoard.h"

#include <QLineF>
#include <QPointF>

extern GameBoard* gameboard;
extern MyPlayer* player;

/**
 * @brief the enemymass constructor, creates the enemy's mass to shoot
 * Sets image and size of the mass
 */
EnemyMass::EnemyMass(QObject* parent) :
    QObject(parent)
{
    QPixmap enemymass_pix(":/Massive/enemymass.png");
    this->setPixmap(enemymass_pix);
    this->setScale(0.1);

    //create a timer for how long the enemy mass travels
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(movemass()));
    timer->start(50);
}

//makes the enemy mass move
void EnemyMass::movemass() {
    //if mass hits user
    QList <QGraphicsItem*> hit_list = collidingItems();
    //increment through list
    for (int i = 0; i < hit_list.size(); i++) {
        //if mass hits player
        if (typeid(*(hit_list[i])) == typeid(MyPlayer)) {
            //decrease the score
            gameboard->displayscore->subtract();

            //decrease user's size by decreasing scale relative to current size
            player->setScale(player->scale() * 0.7);

            //remove mass from scene
            scene()->removeItem(this);
            delete this;
            //if user is hit by the enemy and score is less than zero
            if (gameboard->displayscore->score < 0)
                gameboard->gameOver();
            return;
        }
    }

    /*target = new QPointF;
    target->setX(gameboard->player->x());
    target->setY(gameboard->player->y());

    QLineF ln(QPointF(x(), y()), target);
    int angle = -1 * ln.angle();

    this->setRotation(angle);*/
    setPos(x(),y()+10);

    //delete enemy mass that goes off the screen
    if (pos().y() < 0) {
        scene()->removeItem(this);
        delete this;
    }
    if (pos().x() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
