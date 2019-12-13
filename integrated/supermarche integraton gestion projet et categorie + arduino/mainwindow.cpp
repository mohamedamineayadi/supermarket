#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"personnel.h"
#include"arduino_capteur.h"
#include"caissevente.h"
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

void MainWindow::on_pushButton_3_clicked()
{
    pro = new prodcat(this);
    pro->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    ard = new arduino_capteur(this);
    ard->show();
}

void MainWindow::on_pushButton_clicked()
{
    cv = new CaisseVente(this);
    cv->show();
}
