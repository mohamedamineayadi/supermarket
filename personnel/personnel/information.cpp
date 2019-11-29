#include "information.h"
#include <QDebug>
Information::Information()
{
id=0;
nom="";
prenom="";
sexe="";
etat="";
adresse="";
departement="";
salaire=0;
commision=0;
nbr_prs=0;
nbr_abs=0;
}
Information::Information(int id,QString nom,QString prenom,QString sexe,QString etat,QString adresse,QString departement,int salaire,int commision,int nbr_prs,int nbr_abs)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
   this->sexe=sexe;
   this->etat=etat;
    this->adresse=adresse;
    this->departement=departement;
    this->salaire=salaire;
    this->commision=commision;
    this->nbr_prs=nbr_prs;
    this->nbr_abs=nbr_abs;
}

QString Information::get_nom(){return  nom;}
QString Information::get_prenom(){return prenom;}
QString Information::get_sexe(){return sexe;}
QString Information::get_etat(){return etat;}
QString Information::get_departement(){return departement;}
int Information::get_id(){return  id;}
int Information::get_salaire(){return  salaire;}
int Information::get_commision(){return  commision;}
int Information::get_nbr_abs(){return  nbr_abs;}
int Information::get_nbr_prs(){return  nbr_prs;}
bool Information::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString res1= QString::number(salaire);
QString res2= QString::number(commision);
QString res3= QString::number(nbr_prs);
QString res4= QString::number(nbr_abs);
query.prepare("INSERT INTO information (ID, NOM, PRENOM ,SEXE ,ETAT ,ADRESSE ,DEPARTEMENT ,SALAIRE ,COMMISION ,NBR_PRS ,NBR_ABS) "
                    "VALUES (:id, :nom, :prenom, :sexe, :etat, :adresse, :departement, :salaire, :commision, :nbr_prs, :nbr_abs)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":sexe", sexe);
query.bindValue(":etat", etat);
query.bindValue(":adresse", adresse);
query.bindValue(":departement", departement);
query.bindValue(":salaire", res1);
query.bindValue(":commision", res2);
query.bindValue(":nbr_prs", res3);
query.bindValue(":nbr_abs", res4);


return    query.exec();
}

QSqlQueryModel * Information::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from information");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Departement"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Salaire"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Commision"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("Nombre de presence"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("Nombre d'absence"));
    return model;
}

bool Information::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from information where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Information::modifierinformation(int id,QString nom,QString prenom,QString sexe,QString etat,QString adresse,QString departement,int salaire,int commision,int nbr_prs,int nbr_abs)
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(salaire);
    QString res2= QString::number(commision);
    QString res3= QString::number(nbr_prs);
    QString res4= QString::number(nbr_abs);
    query.prepare("UPDATE information set ID=:id, NOM=:nom, PRENOM=:prenom ,SEXE=:sexe ,ETAT=:etat ,ADRESSE=:adresse ,DEPARTEMENT=:departement ,SALAIRE=:salaire ,COMMISION=:commision ,NBR_PRS=:nbr_prs ,NBR_ABS= :nbr_abs where ID=:id") ;

    query.bindValue(":id", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":sexe", sexe);
    query.bindValue(":etat", etat);
    query.bindValue(":adresse", adresse);
    query.bindValue(":departement", departement);
    query.bindValue(":salaire", res1);
    query.bindValue(":commision", res2);
    query.bindValue(":nbr_prs", res3);
    query.bindValue(":nbr_abs", res4);

        return    query.exec();


}

QSqlQueryModel * Information::chercher(int id)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from information WHERE ID=:id"));

     query.bindValue(":id",id);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("SEXE"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("DEPARTEMENT"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("COMMISION"));
     model->setHeaderData(8, Qt::Horizontal, QObject::tr("NBR_PRS"));
     model->setHeaderData(9, Qt::Horizontal, QObject::tr("NBR_ABS"));


return model;
 }
QSqlQueryModel * Information::trie_information()
 { QSqlQueryModel * model = new QSqlQueryModel();

   model->setQuery(QString("select * from information order by ID asc "));
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("SEXE"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("DEPARTEMENT"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("COMMISION"));
   model->setHeaderData(8, Qt::Horizontal, QObject::tr("NBR_PRS"));
   model->setHeaderData(9, Qt::Horizontal, QObject::tr("NBR_ABS"));



    return model;
 }
