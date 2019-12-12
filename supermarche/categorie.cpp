#include "categorie.h"
#include <QString>
#include <QSqlQuery>

categorie::categorie()
{
    idcat=0;
    nomcat="";
}
categorie::categorie(int idcat,QString nomcat)
{
  this->idcat=idcat;
  this->nomcat=nomcat;
}
int categorie::get_idcat(){return  idcat;}
QString categorie::get_nomcat(){return  nomcat;}
bool categorie::ajouter()
{
QSqlQuery query;
QString res= QString::number(idcat);
query.prepare("INSERT INTO categories (IDCAT, NOMCAT) "
                    "VALUES (:idcat, :nomcat)");
query.bindValue(":idcat", idcat);
query.bindValue(":nomcat", nomcat);


return    query.exec();
}

QSqlQueryModel * categorie::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from categories");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID categorie"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom categorie"));

    return model;
}
QSqlQueryModel * categorie::afficher_recherche(int ref)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare(QString("select * from categories where IDCAT=:ref"));
    q.bindValue(":ref",ref);
    q.exec();
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID categorie"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom categorie"));

    return model;
}

QSqlQueryModel * categorie::afficherTri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from categories order by  IDCAT asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID categorie"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom categorie"));

    return model;
}
bool categorie::modifier(int idcat,QString nomcat)
{
    QString res = QString::number (idcat) ;

        QSqlQuery query;
        query.prepare("UPDATE categories set NOMCAT=:nomcat where IDCAT=:idcat");
        query.bindValue(":idcat",res);
        query.bindValue(":nomcat",nomcat);

        return    query.exec();


}
bool categorie::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from categories where IDCAT = :idcat ");
query.bindValue(":idcat", res);
return    query.exec();
}
categorie categorie::rechercher(int idcat)
{
categorie *cat= new categorie();

      QSqlQuery q;

      q.prepare("SELECT * FROM PRODUIT WHERE idcat=?");
      q.addBindValue(idcat);
      q.exec();
      if(q.next())
      {
      int idcat = q.value(1).toInt();
      QString nomcat = q.value(2).toString();


  cat= new categorie(idcat,nomcat);

  return *cat;
      }

      return *cat;
 }

