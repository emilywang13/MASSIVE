/** @file gameboard.cpp
 *  @brief Implementation for GameBoard class
 *  Implements slots of widgets of the game board
 */

#include "GameBoard.h"
#include "ui_gameboard.h"
#include <QPixmap>
#include <QKeyEvent>
#include <QTimer>
#include "Enemy.h"
#include "enemymass.h"
#include "score.h"
#include "instructions.h"
#include "gameover.h"

MyPlayer* player;

/**
 * @brief GameBoard constructors, creates the gameboard after pressing start
 * @param charchoice, the character choice
 * @param parent, the parent widget
 */
GameBoard::GameBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameBoard)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white");
}

GameBoard::GameBoard(int charchoice, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameBoard)
 {
    ui->setupUi(this);
    this->setStyleSheet("background-color: white");


    //create a scene
    scene = new QGraphicsScene();

    //create the player and add the appropriate image for the character choice
    //MyPlayer * player = new MyPlayer();
    player = new MyPlayer();
    if (charchoice == 1) {
        QPixmap p1(":/Massive/first.jpg");
        player->setPixmap(p1);
        player->setPixmap(p1.scaledToHeight(50));
    }
    else if (charchoice == 2) {
        QPixmap p2(":/Massive/second.png");
        player->setPixmap(p2);
        player->setPixmap(p2.scaledToHeight(50));
    }
    else {
        QPixmap p3(":/Massive/third.png");
        player->setPixmap(p3);
        player->setPixmap(p3.scaledToHeight(50));
    }


    //add item to scene
    scene->addItem(player);

    //set focus on player, allows player to be movable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add a view
    view = new QGraphicsView(scene);

    //set dimensions of the view
    view->setFixedWidth(900);
    view->setFixedHeight(700);
    scene->setSceneRect(0,0,900,700);

    player->setPos(100, 400);

    //create enemies and their mass to shoot
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(create()));
    timer->start(5000);

    //add the score
    displayscore = new Score();
    scene->addItem(displayscore);

    //spawn food items
    foodtimer = new QTimer();
    QObject::connect(foodtimer, SIGNAL(timeout()), player, SLOT(makefood()));
    foodtimer->start(10000);

    //play background theme song
    song = new QMediaPlayer();
    song->setMedia(QUrl("qrc:/sounds/song.mp3"));
    //create a timer to restart song
    QTimer* t = new QTimer();
    QObject::connect(t, SIGNAL(timeout()), song, SLOT(play()));
    t->start(70);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
}

//what happens when game is over
void GameBoard::gameOver() {
    //clear screen
    delete scene;

    //stop song
    delete song;

    //close the gameboard window
    view->close();

    //play losing sound effect when game over
    QMediaPlayer* losingsong = new QMediaPlayer();
    losingsong->setMedia(QUrl("qrc:/sounds/lost.mp3"));
    losingsong->play();

    //open new gameover window
    gameover = new GameOver(this);
}

//destructor
GameBoard::~GameBoard()
{
    delete ui;
}
