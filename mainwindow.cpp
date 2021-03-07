#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string.h>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    char *token;
    char dot[2] = ".";

    //claim values from the input boxes
    int IntegerHours = ui->spinBox->value();
    int IntegerMinutes = ui->spinBox_2->value();
    int IntegerPause = ui->spinBox_3->value();
    float FloatLength = ui->doubleSpinBox->value();

    //cast the integers to float ((f)hours etc)
    float FloatHours = (float) IntegerHours;
    float FloatMinutes = (float) IntegerMinutes;
    float FloatPause = (float) IntegerPause;

    //calculate the time to decimal hours
    float FloatTime = FloatHours + (FloatMinutes / 60) + (FloatPause /60);
    FloatTime = FloatTime + FloatLength;

    //convert the decimal hours float to a char
    char CharTime[10];
    snprintf(CharTime, sizeof(CharTime), "%0.4f\n", FloatTime);

    //split the hours away from the char string and call it hours(n)
    token = strtok(CharTime, dot);
    char *CharHours;
    CharHours = token;

    //split the minutes away from the char string and call it one
    token = strtok(NULL, dot);
    char *PartOfCharMinutes;
    PartOfCharMinutes = token;

    //put a 0. in front of the minutes char
    char CharMinutes[10] = "0.";
    strcat(CharMinutes, PartOfCharMinutes);

    //convert the minutes char with 0. in its front to a float,
    //and call it minute(f)
    float FinalMinutes = atof(CharMinutes);

    //calculate the real minutes out from decimal
    FinalMinutes = FinalMinutes * 60;

    //cast the minutes float to a integer
    int FinalIntMinutes = (int)FinalMinutes;

    //convert the hours char to a integer
    int FinalIntHours = atoi(CharHours);

    //prepare output string (hours:minutes)
    QString text = QString("Uhrzeit %1:").arg(FinalIntHours);
    text.append(QString::number(FinalIntMinutes));

    //output the result
    ui->lineEdit->setText(text);
}
