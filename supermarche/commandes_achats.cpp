#include "commandes_achats.h"
#include <QtDebug>
#include <iostream>
commandes_achats::commandes_achats()
{

ref_cmd="";
date_cmd="";
codefournisseur=0;
idproduit="";
}

commandes_achats:: commandes_achats(QString ref_cmd , QString date_cmd, int codefournisseur, QString idproduit  )
{
    this->ref_cmd=ref_cmd;
    this->date_cmd=date_cmd;
    this->codefournisseur=codefournisseur;
    this->idproduit=idproduit;

}

QString commandes_achats::get_ref_cmd(){return ref_cmd;}
QString commandes_achats ::get_date_cmd(){return date_cmd;}
int commandes_achats :: get_codefournisseur(){return codefournisseur;}
QString commandes_achats ::get_idproduit(){return idproduit;}

bool commandes_achats::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO CMDACHAT (REFCMDA, DATE_CMD,CODEFOURNISSEUR,ID_PRODUIT)"
                 "VALUES (:ref_cmd,:date_cmd,:codefournisseur,:idproduit)");
  query.bindValue(":ref_cmd",ref_cmd);
  query.bindValue(":date_cmd",date_cmd);
  query.bindValue(":codefournisseur",codefournisseur);
  query.bindValue(":idproduit",idproduit);

  return  query.exec();
}

QSqlQueryModel * commandes_achats::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from  CMDACHAT ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFCMDA"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_CMD "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CODEFOURNISSEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_PRODUIT"));

        return model;
}

bool commandes_achats::supprimer(QString id)
{
QSqlQuery query;
query.prepare("Delete from CMDACHAT where REFCMDA = :ref_cmd ");
std::cout << id.toStdString() << std::endl;
query.bindValue(":ref_cmd", id);
return    query.exec();
}

void commandes_achats :: modifier(){
    QSqlQuery query;

    query.prepare("update CMDACHAT  set DATE_CMD = :date_cmd, CODEFOURNISSEUR = :codefournisseur, ID_PRODUIT = :idproduit where REFCMDA = :id ;");
    std::cout << ref_cmd.toStdString() << std::endl;
    query.bindValue(":id", ref_cmd);
    query.bindValue(":date_cmd",date_cmd );
    query.bindValue(":codefournisseur", codefournisseur);
    query.bindValue(":idproduit", idproduit);
    query.exec();
}
QSqlQueryModel * commandes_achats :: sort(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from  CMDACHAT order by REFCMDA ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFCMDA"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_CMD "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CODEFOURNISSEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_PRODUIT"));

        return model;
}
