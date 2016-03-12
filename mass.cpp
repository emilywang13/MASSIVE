/** @file Mass.cpp
 *  @brief Implements functions for the shooted mass particle
 */

#include "Mass.h"
#include <QTimer>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "gameboard.h"

extern GameBoard* gameboard;
/**
 * @brief the mass constructor, creates the mass to shoot
 * Sets image and size of the mass
 */
Mass::Mass()
{
    QPixmap mass_pix(":/Massive/mass.jpeg");
    this->setPixmap(mass_pix);
    this->setScale(0.1);

    //create a timer for how long the mass travels
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

/*void Mass::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    target = event->scenePos();
    //QGraphicsScene::mouseMoveEvent(event);
}*/

//makes the mass move after being shooted
void Mass::move() {
    //if mass hits enemy
    QList <QGraphicsItem*> hit_list = collidingItems();
    //increment through list
    for (int i = 0; i < hit_list.size(); i++) {
        //if mass hits enemy
        if (typeid(*(hit_list[i])) == typeid(Enemy)) {
            //remove mass and enemy from scene
            scene()->removeItem(hit_list[i]);
            scene()->removeItem(this);
            delete hit_list[i];
            delete this;
            return;
        }
    }
    setPos(x(),y()-10);

    //setPos(target);
    //delete mass that goes off the screen
    if (pos().y() < 0) {
        scene()->removeItem(this);
        delete this;
    }
    if (pos().x() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
