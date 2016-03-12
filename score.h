/** @file score.h
 *  @brief declaration for member functions to keep score
 */

#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem {
public:
    Score(QGraphicsItem* parent = 0);
    void add();
    void subtract();
    int getScore();
//private:
    int score;
};

#endif // SCORE_H
