/** @file Food.h
 *  @brief declaration of functions for the food items
 */

#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QMediaPlayer>



class Food: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Food();
public slots:
    void move();
private:
    QTimer* timer;
    QMediaPlayer* foodsoundeffect;
};

#endif // FOOD_H
