#include "dialog_new_caisse.h"
#include "ui_dialog_new_caisse.h"
#include "caisses.h"
#include "caissevente.h"

Dialog_new_caisse::Dialog_new_caisse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_new_caisse)
{
    ui->setupUi(this);
    mSystemTrayIcon = new QSystemTrayIcon;
    mSystemTrayIcon->setVisible(true);
    mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
}

Dialog_new_caisse::~Dialog_new_caisse()
{
    delete ui;
}

void Dialog_new_caisse::on_pushButton_clicked()
{

    int ID_CAISSE = ui->lineEdit_idcaisse->text().toInt();
    int SOLDE_DEP = ui->lineEdit_sd->text().toInt();
    int SOLDE_FINAL = ui->lineEdit_sf->text().toInt();
  caisses caisse(ID_CAISSE,SOLDE_DEP,SOLDE_FINAL);
  bool test=caisse.ajouter();
  if(test)
{
      mSystemTrayIcon->showMessage(tr("Notification!"),tr("Commande ajoutée"));
QMessageBox::information(nullptr, QObject::tr(nullptr),
                  QObject::tr("Commande ajoutée.\n"
                              "Click Ok to exit."), QMessageBox::Ok);

}
  else
      QMessageBox::critical(nullptr, QObject::tr(nullptr),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  hide();
}

void Dialog_new_caisse::on_pushButton_2_clicked()
{
    hide();
}
