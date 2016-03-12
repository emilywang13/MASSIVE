/** @file score.cpp
 *  @brief Implementation for Score class
 *  Implements functions to keep score
 */

#include "Score.h"
#include <QFont>
#include "GameBoard.h"

/**
 * @brief Score constructor
 * Sets color and font to display the score
 */

extern GameBoard* gameboard;

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setFont(QFont("Geneva", 20));
    setDefaultTextColor(Qt::red);

}

//add 10 points to score
void Score::add() {
    score += 10;
    setPlainText(QString("Score: ") + QString::number(score));

}

//subtract 10 points from score
void Score::subtract() {
    score -= 10;
    setPlainText(QString("Score: ") + QString::number(score));
}

//return the score
int Score::getScore() {
    return score;
}
