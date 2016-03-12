/** @file Mass.h
 *  @brief declaration of functions for the shooted mass particle
 */

#ifndef MASS_H
#define MASS_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>

class Mass: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Mass();
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
public slots:
    void move();
private:
    //QPointF target;
    QTimer* timer;
};

#endif // MASS_H
