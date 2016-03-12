/** @file myplayer.h
 *  @brief declaration for functions of the user's character
 */

#ifndef MYPLAYER_H
#define MYPLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include "enemy.h"
#include "enemymass.h"

class MyPlayer: public QObject, public QGraphicsPixmapItem {
   Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
public slots:
    void create();
    void makefood();
};

#endif // MYPLAYER_H
