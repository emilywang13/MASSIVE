/** @file enemy.h
 *  @brief declaration for member functions for the enemy
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPointF>

class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy();
public slots:
    void move();
    void shootmass();

    void findtarget();
private:
    QTimer* timer;
    QTimer* masstimer;
    QPointF* target;
};

#endif // ENEMY_H
