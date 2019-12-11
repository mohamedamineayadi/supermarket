#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"personnel.h"

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


void MainWindow::on_pushButton_2_clicked()
{
   per = new personnel(this) ;
   per->show() ;

}

void MainWindow::on_pushButton_4_clicked()
{
    client = new client_fidelite(this) ;
    client->show() ;
}