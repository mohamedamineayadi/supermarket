#include "fournisseur.h"
#include <QDebug>
Fournisseur::Fournisseur()
{
codefournisseur=0;
nom="";
adresse="";
email="";
fax=0;
teleph=0;
}
Fournisseur::Fournisseur(int codefournisseur,QString nom,QString adresse,QString email, int fax,int teleph)
{
  this->codefournisseur=codefournisseur;
  this->nom=nom;
  this->adresse=adresse;
    this->email=email;
    this->fax=fax;
    this->teleph=teleph;
}
QString Fournisseur::get_nom(){return  nom;}
QString Fournisseur::get_adresse(){return adresse;}
QString Fournisseur ::get_email(){return  email;}
int Fournisseur::get_codefournisseur(){return  codefournisseur;}
int Fournisseur::get_fax(){return  fax;}
int Fournisseur::get_teleph(){return  teleph;}


bool Fournisseur::ajouter()
{
QSqlQuery query;
QString res= QString::number(codefournisseur);
query.prepare("INSERT INTO fournisseur (CODEFOURNISSEUR, NOM, ADRESSE,TELEPHONE,FAX,EMAIL) "
                    "VALUES (:codefournisseur, :nom, :adresse,:telephone,:fax,:email)");
query.bindValue(":codefournisseur", res);
query.bindValue(":nom", nom);
query.bindValue(":adresse", adresse);
query.bindValue(":telephone", teleph);
query.bindValue(":fax", fax);
query.bindValue(":email", email);



return    query.exec();
}

QSqlQueryModel * Fournisseur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from fournisseur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODEFOURNISSEUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("telephone"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("fax"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("email"));
    return model;
}

bool Fournisseur::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Fournisseur where CODEFOURNISSEUR = :codefournisseur ");
query.bindValue(":codefournisseur", res);
return    query.exec();
}

void Fournisseur :: modifier(){
    QSqlQuery query;
    QString res= QString::number(codefournisseur);
    query.prepare("update fournisseur  set "
                  "nom = :nom, adresse = :adresse, telephone = :telephone, fax = :fax,"
                  "email = :email where codefournisseur = :id ;");
    query.bindValue(":id", codefournisseur);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":telephone", teleph);
    query.bindValue(":fax", fax);
    query.bindValue(":email", email);
    query.exec();
}
