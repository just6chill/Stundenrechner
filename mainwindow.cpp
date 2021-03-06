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

    int hours = ui->spinBox->value();
    int minutes = ui->spinBox_2->value();
    int pauses = ui->spinBox_3->value();
    float flength = ui->doubleSpinBox->value();

    float fhours = (float) hours;
    float fminutes = (float) minutes;
    float fpauses = (float) pauses;
    float ftime = fhours + (fminutes / 60) + (pauses /60);

    ftime = ftime + flength;
    char ctime[10];
    snprintf(ctime, sizeof(ctime), "%0.4f\n", ftime);
    token = strtok(ctime, dot);
    char *hoursn;
    hoursn = token;
    token = strtok(NULL, dot);
    char *one;
    one = token;
    char minuten[10] = "0.";
    strcat(minuten, one);

    float minutef = atof(minuten);
    minutef = minutef * 60;
    int minute = (int) minutef;
    int hour = atoi(hoursn);
    QString text = QString("Uhrzeit %1:").arg(hour);
    text.append(QString::number(minute));

    ui->lineEdit->setText(text);
}
