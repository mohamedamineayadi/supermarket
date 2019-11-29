#include "client.h"
#include <QDebug>
client::client()
{
id=0;
nom="";
prenom="";
tel="";
sexe="";
mail="";
}
client::client (int id,QString nom,QString prenom,QString tel,QString sexe,QString mail)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
    this->tel=tel;
    this->sexe=sexe;
    this->mail=mail;
}
QString client::get_nom(){return  nom;}
QString client::get_prenom(){return prenom;}
int client::get_id(){return  id;}
QString client::get_sexe(){return  sexe;}
QString client::get_mail(){return mail;}
QString client::get_tel(){return  tel;}

bool client::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO client (ID, NOM, PRENOM,SEXE,MAIL,TEL) "
                    "VALUES (:id, :nom, :prenom,:sexe,:tel,:mail)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":sexe", sexe);
query.bindValue(":tel", tel);
query.bindValue(":mail", mail);

return    query.exec();
}

QSqlQueryModel * client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));
    return model;
}

bool client::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from client where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool client:: modifierclient (int id,QString nom,QString prenom,QString sexe,QString tel,QString mail)
{
    QString res = QString :: number (id) ;

        QSqlQuery q;
         q.prepare("UPDATE client set NOM =:nom ,PRENOM=:prenom,SEXE =:sexe,TEL=:tel,MAIL=:mail where ID=:id");
         q.bindValue(":id",res);
        q.bindValue(":nom",nom);
         q.bindValue(":prenom",prenom);
         q.bindValue(":sexe",sexe);
          q.bindValue(":tel",tel);
          q.bindValue(":mail",mail);




        return    q.exec();


}
QSqlQueryModel * client::chercher(int id)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from client WHERE id=:id"));

     query.bindValue(":id",id);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel "));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));


return model;
 }
QSqlQueryModel * client::trie_nom()
 { QSqlQueryModel * model = new QSqlQueryModel();

   model->setQuery(QString("select * from client order by NOM asc "));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));



    return model;
 }
