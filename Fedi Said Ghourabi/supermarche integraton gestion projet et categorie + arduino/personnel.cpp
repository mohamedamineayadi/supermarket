#include "personnel.h"
#include "ui_personnel.h"
#include"information.h"
#include"conge.h"

#include <QMessageBox>
#include <QSystemTrayIcon>

personnel::personnel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::personnel)
{
    mysystem=new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);

    ui->setupUi(this);
}

personnel::~personnel()
{
    delete ui;
}




void personnel::on_pushButton_ajouter_clicked()
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
                  QObject::tr("Informatiosn ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void personnel::on_pushButton_modifier_clicked()
{
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

void personnel::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_supprimer->text().toInt();
    bool test=tmpinformation.supprimer(id);
    if(test)
    {ui->tabinformation->setModel(tmpinformation.afficher());//refresh
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un personnel"),
                    QObject::tr("information supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void personnel::on_pushButton_recherche_clicked()
{
    int id = ui->lineEdit_recherche->text().toInt();
    ui->tabinformation->setModel(tmpinformation.chercher(id));
}

void personnel::on_pushButton_tri_clicked()
{
    ui->tabinformation->setModel(tmpinformation.trie_information());
}

void personnel::on_pushButton_actualiser_clicked()
{
      ui->tabinformation->setModel(tmpinformation.afficher());
}

void personnel::on_pushButton_2_clicked()
{
    hide() ;
}

void personnel::on_pushButton_3_clicked()
{
    hide() ;
}

void personnel::on_pushButton_ajouter_2_clicked()
{
    mysystem->showMessage(tr("Notification"),tr("Le congé a été ajouté"));

    int id_conge = ui->lineEdit_id_conge->text().toInt();
    int id = ui->lineEdit_id_2->text().toInt();
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

void personnel::on_pushButton_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
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

void personnel::on_pushButton_6_clicked()
{
    int id = ui->lineEdit_recherche_2->text().toInt();
    ui->tabconge->setModel(tmpconge.chercher(id));
}

void personnel::on_pushButton_5_clicked()
{
    ui->tabconge->setModel(tmpconge.trie_conge());

}

void personnel::on_pushButton_modifier_2_clicked()
{
    int id_conge = ui->lineEdit_id_conge->text().toInt();
    int id = ui->lineEdit_id_2->text().toInt();
     int nbr_conge = ui->lineEdit_nbr_conge->text().toInt();
      int debut_conge = ui->lineEdit_debut_conge->text().toInt();
       int fin_conge = ui->lineEdit_fin_conge->text().toInt();
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

void personnel::on_pushButton_4_clicked()
{
    ui->tabconge->setModel(tmpconge.afficher());

}
