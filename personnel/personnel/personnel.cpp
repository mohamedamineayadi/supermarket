#include "personnel.h"
#include <QDebug>

personnel::personnel()
{
id=0;
nom="";
prenom="";
date_naissance="";
adresse="";
salaire=0;
service="";
statue="";
}
personnel::personnel(int id,QString nom,QString prenom ,QString date_naissance ,QString adresse ,int salaire ,QString service ,QString statue)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->date_naissance=date_naissance;
    this->adresse=adresse;
    this->salaire=salaire;
    this->service=service;
    this->statue=statue;
}
QString personnel::get_nom(){return  nom;}
QString personnel::get_prenom(){return prenom;}
QString personnel::get_date_naissance(){return date_naissance;}
QString personnel::get_adresse(){return adresse;}
QString personnel::get_service(){return service;}
QString personnel::get_statue(){return statue;}
int personnel::get_salaire(){return  salaire;}
int personnel::get_id(){return  id;}

bool personnel::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO etudiant (ID, NOM, PRENOM,DATE_NAISSANCE,ADRESSE,SALAIRE,SERVICE,STATUE) "
                    "VALUES (:id, :nom, :prenom, :date_naissance, :adresse, :salaire, :service, :statue)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":date_naissance", date_naissance);
query.bindValue(":adresse", adresse);
query.bindValue(":salaire", res);
query.bindValue(":service", service);
query.bindValue(":statue", statue);

return    query.exec();
}
QSqlQueryModel * personnel::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from personnel");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de naissance"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Service"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Statue"));


    return model;
}

bool personnel::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from etudiant where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
