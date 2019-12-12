#include "fidelite.h"
#include <QDebug>
fidelite::fidelite()
{
points=0;
code=0;
id=0;
}
fidelite:: fidelite(int code,int points,int id)
{
    this->id=id;
  this->points=points;
  this->code=code;

}
int fidelite::get_code(){return  code;}
int fidelite::get_id(){return  id;}
int fidelite::get_points(){return  points;}

bool fidelite::ajouter()
{
QSqlQuery query;
QString res3= QString::number(id);
QString res= QString::number(points);
QString res2= QString::number(code);
query.prepare("INSERT INTO CARTE_FEDELITE (CODE,POINTS,ID) "
                    "VALUES ( :code, :points,:id)");

query.bindValue(":code", res2);
query.bindValue(":points", res);
query.bindValue(":id", res3);


return    query.exec();
}

QSqlQueryModel * fidelite::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from carte_fedelite");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("points"));



    return model;
}

bool fidelite::supprimer(int codes)
{
QSqlQuery query;
QString res= QString::number(codes);
query.prepare("Delete from carte_fedelite where CODE = :code ");
query.bindValue(":code", res);
          return query.exec();
}

bool fidelite:: modifierfidelite (int id,int code,int points)
{
     QString res3 = QString :: number (id) ;
    QString res = QString :: number (code) ;
    QString res2 = QString :: number (points) ;
        QSqlQuery q;
         q.prepare("UPDATE carte_fedelite set CODE =:code,POINTS=:points,ID=:id where CODE=:code ");
         q.bindValue(":id",res3);
         q.bindValue(":code",res);
        q.bindValue(":points",res2);

        return    q.exec();


}

QSqlQueryModel * fidelite::trie_points()
 { QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery(QString("SELECT * FROM carte_fedelite ORDER BY POINTS "));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("points "));

    return model;
 }


QSqlQueryModel * fidelite::chercher(int code )
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from carte_fedelite WHERE code=:code"));

     query.bindValue(":code",code);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("code"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("points"));


return model;
 }
