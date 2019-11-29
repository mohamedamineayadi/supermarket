#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "information.h"
#include "conge.h"
#include <QMessageBox>
#include <QPixmap>
#include <QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    mysystem=new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);

ui->setupUi(this);
ui->tabinformation->setModel(tmpinformation.afficher());
ui->tabconge->setModel(tmpconge.afficher());
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
     mysystem->showMessage(tr("Notification"),tr("Le personnel a été ajouté"));
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString sexe= ui->lineEdit_sexe->text();
    QString etat= ui->lineEdit_etat->text();
    QString adresse= ui->lineEdit_adresse->text();
    QString departement= ui->lineEdit_departement->text();
     int salaire = ui->lineEdit_salaire->text().toInt();
      int commision = ui->lineEdit_commision->text().toInt();
       int nbr_prs = ui->lineEdit_nbr_prs->text().toInt();
       int nbr_abs = ui->lineEdit_nbr_abs->text().toInt();
  Information e(id,nom,prenom,sexe,etat,adresse,departement,salaire,commision,nbr_prs,nbr_abs);
  bool test=e.ajouter();
  if(test)
{ui->tabinformation->setModel(tmpinformation.afficher());//refresh
QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("Information ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpinformation.supprimer(id);
if(test)
{ui->tabinformation->setModel(tmpinformation.afficher());//refresh
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un personnel"),
                QObject::tr("information supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un personnel"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int id_conge = ui->lineEdit_id_conge->text().toInt();
    int id = ui->lineEdit_id_3->text().toInt();
     int nbr_conge = ui->lineEdit_nbr_conge->text().toInt();
      int debut_conge = ui->lineEdit_debut_conge->text().toInt();
       int fin_conge = ui->lineEdit_fin_conge->text().toInt();

  conge e(id_conge,id,nbr_conge,debut_conge,fin_conge);
  bool test=e.ajouter();
  if(test)
{ui->tabconge->setModel(tmpconge.afficher());//refresh
QMessageBox::critical(nullptr, QObject::tr("Ajouter un conge"),
                  QObject::tr("conge ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un conge"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pushButton_clicked()
{
    int id = ui->lineEdit_id_4->text().toInt();
    bool test=tmpconge.supprimer(id);
    if(test)
    {ui->tabconge->setModel(tmpconge.afficher());//refresh
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un conge"),
                    QObject::tr("conge supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un conge"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{

    int id = ui->lineEdit->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString prenom= ui->lineEdit_3->text();
    QString sexe= ui->lineEdit_4->text();
    QString etat= ui->lineEdit_51->text();
    QString adresse= ui->lineEdit_6->text();
    QString departement= ui->lineEdit_7->text();
     int salaire = ui->lineEdit_8->text().toInt();
      int commision = ui->lineEdit_9->text().toInt();
       int nbr_prs= ui->lineEdit_10->text().toInt();
       int nbr_abs = ui->lineEdit_11->text().toInt();

       bool test = tmpinformation.modifierinformation(id,nom,prenom,sexe,etat,adresse,departement,salaire,commision,nbr_prs,nbr_abs);
           if (test)
           {
                ui->tabinformation->setModel( tmpinformation.afficher());

               QMessageBox::information(nullptr, QObject::tr("modifier avec sucess !"),
                           QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
           }
           else
               QMessageBox::critical(nullptr, QObject::tr("modifier non sucess !"),
                           QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}







void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->lineEdit_information->text().toInt();
    ui->tabinformation->setModel(tmpinformation.chercher(id));
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->tabinformation->setModel(tmpinformation.trie_information());

}

void MainWindow::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_conge->text().toInt();
    ui->tabconge->setModel(tmpconge.chercher(id));
}

void MainWindow::on_pushButton_6_clicked()
{
  ui->tabconge->setModel(tmpconge.trie_conge());
}

void MainWindow::on_pushButton_7_clicked()
{
    int id_conge = ui->lineEdit_5->text().toInt();
    int id = ui->lineEdit_15->text().toInt();
     int nbr_conge = ui->lineEdit_14->text().toInt();
      int debut_conge = ui->lineEdit_13->text().toInt();
       int fin_conge = ui->lineEdit_12->text().toInt();
       bool test = tmpconge.modifierconge(id_conge,id,nbr_conge,debut_conge,fin_conge);
           if (test)
           {
                ui->tabconge->setModel( tmpconge.afficher());

               QMessageBox::information(nullptr, QObject::tr("modifier avec sucess !"),
                           QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
           }
           else
               QMessageBox::critical(nullptr, QObject::tr("modifier non sucess !"),
                           QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}
