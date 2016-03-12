/** @file Food.cpp
 *  @brief Implements functions for the food item
 */

#include "Food.h"
#include "MyPlayer.h"
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include "GameBoard.h"
#include <QSize>


extern GameBoard* gameboard;

extern MyPlayer* player;
/**
 * @brief the food constructor, creates the food item
 * Sets image and size of the food
 */
Food::Food()
{
    QPixmap food_pix(":/Massive/cake.jpg");
    this->setPixmap(food_pix);
    this->setScale(0.2);

    //set random position
    int random_x = rand() % 800;
    int random_y = rand() % 300;
    setPos(random_x, random_y);

    //create a timer for how frequently food is created
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

    //import the sound effect for when the player eats food
    foodsoundeffect = new QMediaPlayer();
    foodsoundeffect->setMedia(QUrl("qrc:/sounds/foodsound.mp3"));

}

/**
 * @brief If user gets food, remove food from scene and increase score
 */
void Food::move() {
    QList <QGraphicsItem*> hit_list = collidingItems();
    //increment through list
    for (int i = 0; i < hit_list.size(); i++) {
        //if food hits player
        if (typeid(*(hit_list[i])) == typeid(MyPlayer)) {
            //increase the score
            gameboard->displayscore->add();

            //increase user's size by increasing scale relative to current size
            player->setScale(player->scale() * 1.3);

            //play food sound effect
            //if sound already playing, in the case that two foods are next to each other
            if (foodsoundeffect->state() == QMediaPlayer::PlayingState) {
                //restart the sound effect
                foodsoundeffect->setPosition(0);
            }
            else {
                foodsoundeffect->play();
            }

            //remove food from scene
            scene()->removeItem(this);
            delete this;
        }
    }
}


