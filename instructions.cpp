/** @file instructions.cpp
 *  @brief Implementation for Instructions window
 */


#include "instructions.h"
#include "ui_instructions.h"

Instructions::Instructions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Instructions)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: pink");
}

Instructions::~Instructions()
{
    delete ui;
}
