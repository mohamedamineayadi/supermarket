#include "gestionfournisseurcmd.h"
#include "ui_gestionfournisseurcmd.h"
#include "fournisseur.h"
#include "commandes_achats.h"
#include <QMessageBox>
#include <QString>
#include <QMessageBox>
#include <QtDebug>
#include "arduinoo.h"
#include <QSqlRecord>
#include <iostream>
GestionFournisseurCmd::GestionFournisseurCmd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GestionFournisseurCmd)
{
    ui->setupUi(this);
    ui->tabfournisseur->setModel(tmpfournisseur.afficher());
    ui->tabcmd->setModel(tmpcmd.afficher());
    a = new arduinoo();
    a->connect_arduino();
}

GestionFournisseurCmd::~GestionFournisseurCmd()
{
    delete ui;
}

void GestionFournisseurCmd::on_pb_ajouter_fourn_clicked()
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



void GestionFournisseurCmd::on_pb_supprimer_fourn_clicked()
{
    int id = ui->lineEdit_codefourn_supp_2->text().toInt();
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


void GestionFournisseurCmd::on_pb_modifier_clicked()
{
    int qs = ui->lineEdit_codefourn_modifier->text().toInt();
    QSqlQuery query;
    query.prepare("select * from fournisseur where codefournisseur = :id ;");
    query.bindValue(":id", qs);
    query.exec();
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery(query);
    QSqlRecord sr = model->record(0);
    ui->lineEdit_nomfourn_modifier->setText(sr.value(1).toString());
    ui->lineEdit_adresse_modifier->setText(sr.value(2).toString());
    ui->lineEdit_teleph_modifier->setText(sr.value(3).toString());
    ui->lineEdit_fax_modifier->setText(sr.value(4).toString());
    ui->lineEdit_email_modifier->setText(sr.value(5).toString());
}


void GestionFournisseurCmd::on_pushButton_ok_modifier_clicked()
{
    int code = ui->lineEdit_codefourn_modifier->text().toInt();
    QString nom = ui->lineEdit_nomfourn_modifier->text();
    QString adress = ui->lineEdit_adresse_modifier->text();
    int tel = ui->lineEdit_teleph_modifier->text().toInt();
    int fax = ui->lineEdit_fax_modifier->text().toInt();
    QString email = ui->lineEdit_email_modifier->text();
    Fournisseur *f = new Fournisseur(code, nom, adress, email, tel, fax);
    f->modifier();
    delete f;
}


void GestionFournisseurCmd::on_pushButton_actualiser_clicked()
{
    QSqlQuery query;
    query.prepare("select * from fournisseur");
    query.exec();
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery(query);
    ui->tabfournisseur->setModel(model);
}

void GestionFournisseurCmd::on_pb_recherche_fourn_clicked()
{
    QString s = ui->lineEdit_codefourn_recherche->text();
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
        ui->tableView_2->setModel(model);
    }
}


void GestionFournisseurCmd::on_pushButton_ajoutcmd_clicked()
{
    QString ref_cmd =ui->lineEdit_refcmd_ajout->text();
    QString date_cmd= ui->lineEdit_date_ajout->text();
    int codefournisseur=ui->lineEdit_codefourn_ajout->text().toInt();
    QString idproduit=ui->lineEdit_idprod_ajout->text();

    commandes_achats ca(ref_cmd,date_cmd,codefournisseur,idproduit);
    bool test=ca.ajouter(codefournisseur);
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


void GestionFournisseurCmd::on_pushButton_suppcmd_clicked()
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


void GestionFournisseurCmd::on_pushButton_modifiercmd_clicked()
{
    commandes_achats ca(ui->lineEdit_refcmd_modifier->text(),
                        ui->lineEdit_date_modifier->text(),
                        ui->lineEdit_codefourn_modifier_2->text().toInt(),
                        ui->lineEdit_idprod_modifier->text());
ca.modifier();
}


void GestionFournisseurCmd::on_pushButton_rechercher_clicked()
{
    QString qs = ui->lineEdit_refcmd_recherche->text();
        QSqlQuery query;
        query.prepare("select * from CMDACHAT where REFCMDA = :id ;");
        query.bindValue(":id", qs);
        query.exec();
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery(query);
        ui->tableView->setModel(model);
}



void GestionFournisseurCmd::on_pushButton_cherchercmd_clicked()
{
    QSqlQuery q;
    QString ss =ui->lineEdit_refcmd_modifier->text();
    q.prepare("select * from cmdachat where refcmda = :id");
    q.bindValue(":id", ss);
    q.exec();
   QSqlQueryModel * m = new QSqlQueryModel();
   m->setQuery(q);
   QSqlRecord rec;
   rec = m->record(0);
   if(rec.isEmpty() == false){
   ui->lineEdit_date_modifier->setText(rec.value(1).toString());
   ui->lineEdit_codefourn_modifier_2->setText(rec.value(2).toString());
   ui->lineEdit_idprod_modifier->setText(rec.value(3).toString());
   }else{
       std::cout << "efjkf" << std::endl;
   }
}


void GestionFournisseurCmd::on_pushButton_actualisercmd_clicked()
{
   ui->tabcmd->setModel(tmpcmd.afficher());
}


void GestionFournisseurCmd::on_pushButton_triercmd_clicked()
{
   ui->tableView_3->setModel(tmpcmd.sort());
}


void GestionFournisseurCmd::on_pushButton_clicked()
{
        a->write_to_arduino("t");
}


void GestionFournisseurCmd::on_pushButton_2_clicked()
{
    QByteArray i = a->read_from_arduino();
    std::cout << i.toStdString()<< std::endl;
    if (i == ""){
        QMessageBox::critical(nullptr, QObject::tr("message recu"),
                    QObject::tr("Message reçu"), QMessageBox::Cancel);
    }else{
        std::cout << "error" <<std::endl;
    }
}

void GestionFournisseurCmd::on_pushButton_quitt_clicked()
{
    hide();
}
