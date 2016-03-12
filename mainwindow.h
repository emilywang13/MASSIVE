/** @file mainwindow.h
 *  @brief main window declaration for member functions
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QVboxLayout>
#include <QPushButton>
#include <QWidget>
#include <QRadioButton>
#include "GameBoard.h"

/** @namespace Ui
 *  @brief default namespace
 */
namespace Ui {
class MainWindow;
}

/** @class MainWindow
 *  @brief The main window of the program
 *  Contains all slots for widgets
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int charchoice = 1;

public slots:
    void setChar1();
    void setChar2();
    void setChar3();
    void start();
    void help();

private:
    Ui::MainWindow *ui;
    QWidget* main_widget;
    QLabel* Char1;
    QLabel* Char2;
    QLabel* Char3;
    QHBoxLayout* layout;
    QVBoxLayout* main_layout;
    QPushButton* start_button;
    QPushButton* instructions_button;
    QLabel* title;
    QLabel* character_choice;
    QRadioButton* radio_button;
    QRadioButton* radio_button2;
    QRadioButton* radio_button3;
    QHBoxLayout* rbutton_layout;

};

#endif // MAINWINDOW_H
