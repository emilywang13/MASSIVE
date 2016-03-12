/** @file gameover.cpp
 *  @brief Implementation for gameover window
 */


#include "gameover.h"
#include "ui_gameover.h"
#include "mainwindow.h"

//Constructor
GameOver::GameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: pink");
    ui->replay->setText("Replay");
    ui->quit->setText("Quit");
    QObject::connect(ui->replay, SIGNAL(clicked(bool)), this, SLOT(Restart()));
    QObject::connect(ui->quit, SIGNAL(clicked(bool)), this, SLOT(close()));

    this->show();
}

//slot for restarting game button
void GameOver::Restart() {
    this->close();
    //open a new MainWindow
    MainWindow* mainmenu = new MainWindow();
    mainmenu->show();
}

//Destructor
GameOver::~GameOver()
{
    delete ui;
}
