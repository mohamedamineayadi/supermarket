#include "gestionfourcmd.h"
#include "ui_gestionfourcmd.h"
#include "fournisseur.h"
#include "commandes_achats.h"
#include <QMessageBox>
#include <QString>
#include <QMessageBox>
#include <QtDebug>

#include <QSqlRecord>
#include <iostream>
Gestionfourcmd::Gestionfourcmd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestionfourcmd)
{
    ui->setupUi(this);
    ui->tabfournisseur->setModel(tmpfournisseur.afficher());
    ui->tabcmd->setModel(tmpcmd.afficher());
    ui->setupUi(this);
}

Gestionfourcmd::~Gestionfourcmd()
{
    delete ui;
}



void Gestionfourcmd::on_pushButton_ajouter_four_clicked()
{
    int codefournisseur = ui->lineEdit_codefourn_ajout->text().toInt();
    QString nom= ui->lineEdit_nomfourn_ajout->text();
    QString adresse= ui->lineEdit_adresse_ajout->text();
    QString email= ui->lineEdit_email_ajout->text();
    int fax= ui->lineEdit_fax_ajout->text().toInt();
    int teleph= ui->lineEdit_teleph_ajout->text().toInt();
  Fournisseur f(codefournisseur,nom,adresse,email,fax,teleph);
  bool test=f.ajouter();
  if(test)
{ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Fournisseur"),
                  QObject::tr("Fournisseur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void Gestionfourcmd::on_pushButton_supprimer_fourn_clicked()
{
    int id = ui->lineEdit_supprimer_fourn->text().toInt();
    bool test=tmpfournisseur.supprimer(id);
    if(test)
    {ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Fournisseur"),
                    QObject::tr("Fournisseur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Fournisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void Gestionfourcmd::on_pushButton_chercher_clicked()
{
    int qs = ui->lineEdit_codefourn_ajout->text().toInt();
    QSqlQuery query;
    query.prepare("select * from fournisseur where codefournisseur = :id ;");
    query.bindValue(":id", qs);
    query.exec();
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery(query);
    QSqlRecord sr = model->record(0);
    ui->lineEdit_nomfourn_ajout->setText(sr.value(1).toString());
    ui->lineEdit_adresse_ajout->setText(sr.value(2).toString());
    ui->lineEdit_teleph_ajout->setText(sr.value(3).toString());
    ui->lineEdit_fax_ajout->setText(sr.value(4).toString());
    ui->lineEdit_email_ajout->setText(sr.value(5).toString());
}



void Gestionfourcmd::on_pushButton_modifier_fourn_clicked()
{
    int code = ui->lineEdit_codefourn_ajout->text().toInt();
    QString nom = ui->lineEdit_nomfourn_ajout->text();
    QString adress = ui->lineEdit_adresse_ajout->text();
    int tel = ui->lineEdit_teleph_ajout->text().toInt();
    int fax = ui->lineEdit_fax_ajout->text().toInt();
    QString email = ui->lineEdit_email_ajout->text();
    Fournisseur *f = new Fournisseur(code, nom, adress, email, tel, fax);
    f->modifier();
    delete f;
}




void Gestionfourcmd::on_pushButton_actualiser_fourn_clicked()
{
    QSqlQuery query;
    query.prepare("select * from fournisseur");
    query.exec();
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery(query);
    ui->tabfournisseur->setModel(model);
}


void Gestionfourcmd::on_pushButton_recherche_fourn_clicked()
{
    QString s = ui->lineEdit_recherche_fourn->text();
    QSqlQuery query;
    query.prepare("select * from fournisseur where codefournisseur = :id ;");
    query.bindValue(":id", s.toInt());
    query.exec();
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery(query);
    QSqlRecord sr = model->record(0);
    if(sr.isEmpty() == true){
        QMessageBox::critical(nullptr, QObject::tr("warning"),
                    QObject::tr("fournisseur not found 404.\n"), QMessageBox::Cancel);
    }else{
        ui->tabfournisseur->setModel(model);
    }
}





void Gestionfourcmd::on_pushButton_ajouter_cmd_clicked()
{
    QString ref_cmd =ui->lineEdit_refcmd_ajout->text();
    QString date_cmd= ui->lineEdit_date_ajout->text();
    int codefournisseur=ui->lineEdit_codefcmd->text().toInt();
    QString idproduit=ui->lineEdit_idprod_ajout->text();

    commandes_achats ca(ref_cmd,date_cmd,codefournisseur,idproduit);
    bool test=ca.ajouter();
    if(test)
    {
        ui->tabcmd->setModel(tmpcmd.afficher());
        QMessageBox ::information(nullptr,QObject::tr("Ajouter une commande"),
                                  QObject::tr("Commande ajouté.\n"
                                              "click cancel to exit"),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une commande"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestionfourcmd::on_pushButton_supp_cmd_clicked()
{
    QString id = ui->lineEdit_refcmd_supp->text();
    bool test=tmpcmd.supprimer(id);
    if(test)
    {ui->tabcmd->setModel(tmpcmd.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("commande supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void Gestionfourcmd::on_pushButton_modifier_cmd_clicked()
{
    commandes_achats ca(ui->lineEdit_refcmd_ajout->text(),
                        ui->lineEdit_date_ajout->text(),
                        ui->lineEdit_codefcmd->text().toInt(),
                        ui->lineEdit_idprod_ajout->text());
ca.modifier();
}



void Gestionfourcmd::on_pushButton_cherchercmd_clicked()
{
    QSqlQuery q;
    QString ss =ui->lineEdit_refcmd_ajout->text();
    q.prepare("select * from cmdachat where refcmda = :id");
    q.bindValue(":id", ss);
    q.exec();
   QSqlQueryModel * m = new QSqlQueryModel();
   m->setQuery(q);
   QSqlRecord rec;
   rec = m->record(0);
   if(rec.isEmpty() == false){
   ui->lineEdit_date_ajout->setText(rec.value(1).toString());
   ui->lineEdit_codefcmd->setText(rec.value(2).toString());
   ui->lineEdit_idprod_ajout->setText(rec.value(3).toString());
   }else{
       std::cout << "efjkf" << std::endl;
   }
}



/*void Gestionfourcmd::on_pushButton_actualisercmd_clicked()
{
    ui->tabcmd->setModel(tmpcmd.afficher());
}**/



void Gestionfourcmd::on_pushButton_tri_clicked()
{
    ui->tabcmd->setModel(tmpcmd.sort());
}



void Gestionfourcmd::on_pushButton_recherchecmd_clicked()
{
    QString qs = ui->lineEdit_recherchecmd->text();
        QSqlQuery query;
        query.prepare("select * from CMDACHAT where REFCMDA = :id ;");
        query.bindValue(":id", qs);
        query.exec();
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery(query);
        ui->tabcmd->setModel(model);
}



void Gestionfourcmd::on_pushButton_2_clicked()
{
    hide();
}

void Gestionfourcmd::on_pushButton_clicked()
{
    qDebug() << "tzs" ;
    int codefournisseur = ui->lineEdit_codefourn_ajout->text().toInt();
    QString nom= ui->lineEdit_nomfourn_ajout->text();
    QString adresse= ui->lineEdit_adresse_ajout->text();
    QString email= ui->lineEdit_email_ajout->text();
    int fax= ui->lineEdit_fax_ajout->text().toInt();
    int teleph= ui->lineEdit_teleph_ajout->text().toInt();
  Fournisseur f(codefournisseur,nom,adresse,email,fax,teleph);
  bool test=f.ajouter();
  if(test)
{ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Fournisseur"),
                  QObject::tr("Fournisseur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
