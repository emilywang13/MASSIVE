/** @file mainwindow.cpp
 *  @brief Implementation for MainWindow class
 *  Implements slots of widgets.
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameboard.h"
#include "instructions.h"

GameBoard* gameboard;

/** MainWindow constructor, displays the main screen
 *  @param parent the parent widget
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white");

    main_widget = new QWidget;
    main_layout = new QVBoxLayout;

    //show the title
    title = new QLabel("Welcome to MASSIVE");
    title->setStyleSheet("QLabel {background-color: beige; font-family: Geneva; font-size: 30px}");
    title->setAlignment(Qt::AlignCenter);
    main_layout->addWidget(title);
    main_widget->setLayout(main_layout);


    character_choice = new QLabel("Choose your character!");
    character_choice->setStyleSheet("QLabel {font-family: Brush Script MT; font: italic; font-size: 50px}");
    character_choice->setAlignment(Qt::AlignCenter);
    main_layout->addWidget(character_choice);


    //show the characters
    Char1 = new QLabel;
    Char2 = new QLabel;
    Char3 = new QLabel;

    //set images to the characters
    QPixmap char1_pix(":/Massive/first.jpg");
    Char1->setPixmap(char1_pix);
    Char1->setScaledContents(true);

    QPixmap char2_pix(":/Massive/second.png");
    Char2->setPixmap(char2_pix);
    Char2->setScaledContents(true);

    QPixmap char3_pix(":/Massive/third.png");
    Char3->setPixmap(char3_pix);
    Char3->setScaledContents(true);

    //create horizontal layout for character images
    layout = new QHBoxLayout;
    layout->addWidget(Char1);
    layout->addWidget(Char2);
    layout->addWidget(Char3);
    main_layout->addLayout(layout);

    //create radio buttons for character selection
    radio_button = new QRadioButton;
    radio_button2 = new QRadioButton;
    radio_button3 = new QRadioButton;
    rbutton_layout = new QHBoxLayout;
    rbutton_layout->addWidget(radio_button);
    rbutton_layout->addWidget(radio_button2);
    rbutton_layout->addWidget(radio_button3);
    QObject::connect(radio_button, SIGNAL(clicked(bool)), this, SLOT(setChar1()));
    QObject::connect(radio_button2, SIGNAL(clicked(bool)), this, SLOT(setChar2()));
    QObject::connect(radio_button3, SIGNAL(clicked(bool)), this, SLOT(setChar3()));
    main_layout->addLayout(rbutton_layout);

    //create start button
    start_button = new QPushButton("Start!");
    main_layout->addWidget(start_button);
    QObject::connect(start_button, SIGNAL(clicked(bool)), this, SLOT(start()));
    start_button->show();

    //create instructions button
    instructions_button = new QPushButton("Instructions");
    main_layout->addWidget(instructions_button);
    QObject::connect(instructions_button, SIGNAL(clicked(bool)), this, SLOT(help()));
    instructions_button->show();

    this->setCentralWidget(main_widget);

    //set fixed size of screen
    this->setFixedWidth(700);
    this->setFixedHeight(500);
}

/// Sets the character choice based on main menu selection
void MainWindow::setChar1() {
    charchoice = 1;
}

void MainWindow::setChar2() {
    charchoice = 2;
}

void MainWindow::setChar3() {
    charchoice = 3;
}

/**
 * @brief create the gameboard after pressing the start button
 */
void MainWindow::start() {
    //clear screen
    this->close();
    gameboard = new GameBoard(charchoice, this);
    this->setCentralWidget(gameboard);

    //GameBoard* pt = dynamic_cast<GameBoard*>(this->centralWidget());
}

/**
  @brief opens instructions window after pushing button
  */
void MainWindow::help() {
    //open new window
    Instructions* instruct = new Instructions(this);
    instruct->show();
}

/** MainWindow destructor
 *  @brief default destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}
