/** @file Enemy.cpp
 *  @brief Implements functions for the enemy
 */

#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "EnemyMass.h"

/**
 * @brief the enemy constructor, creates the enemy to shoot at user
 * Sets image and properties of enemy
 */
Enemy::Enemy()
{
    //set image
    QPixmap enemy_pix(":/Massive/enemy.png");
    this->setPixmap(enemy_pix);
    this->setScale(0.6);

    //set random position
    int random_x = rand() % 800;
    int random_y = -rand() % 600;
    setPos(random_x, random_y);

    //create a timer for how long the enemy travels
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

    //create a timer for how frequenly the enemy shoots mass
    masstimer = new QTimer();
    connect(masstimer, SIGNAL(timeout()), this, SLOT(shootmass()));
    masstimer->start(2000);
}

/*void Mass::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    target = event->scenePos();
    //QGraphicsScene::mouseMoveEvent(event);
}*/

//makes the enemy move
void Enemy::move() {
    //let the enemy move in the direction of your player
    if (pos().y() < 700)
        setPos(x(),y()+ 5);
    //if the enemy is off the screen
    else {
        scene()->removeItem(this);
        delete this;
    }
}

//make the enemy create and shoot mass
void Enemy::shootmass() {
    EnemyMass * emass = new EnemyMass(this);
    emass->setPos(x() + 10, y() + 10);

    scene()->addItem(emass);
}

void Enemy::findtarget()
{
    //Player* player
}
