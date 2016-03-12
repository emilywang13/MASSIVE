/** @file EnemyMass.h
 *  @brief declaration of functions for the enemy's shooted mass particle
 */

#ifndef ENEMYMASS_H
#define ENEMYMASS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

#include "GameBoard.h"

class EnemyMass: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    EnemyMass(QObject* parent);

public slots:
    void movemass();
private:
    QTimer* timer;

    QPointF* target;
    //need reference to gameboard
    //GameBoard& gameboard;
};

#endif // ENEMYMASS_H
