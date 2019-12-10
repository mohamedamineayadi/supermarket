#include "fidelite.h"
#include <QDebug>
fidelite::fidelite()
{
points=0;
code=0;

}
fidelite:: fidelite(int points,int code)
{
  this->points=points;
  this->code=code;

}
int fidelite::get_code(){return  code;}

int fidelite::get_points(){return  points;}

bool fidelite::ajouter()
{
QSqlQuery query;
QString res= QString::number(points);
QString res2= QString::number(code);
query.prepare("INSERT INTO carte_fidelite (CODE, POINTS) "
                    "VALUES (:code, :points)");
query.bindValue(":code", res2);
query.bindValue(":points", res);


return    query.exec();
}

QSqlQueryModel * fidelite::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from carte_fidelite");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("points"));

    return model;
}

bool fidelite::supprimer(int code)
{
QSqlQuery query;
QString res= QString::number(code);
query.prepare("Delete from carte_fidelite where CODE =: code ");
query.bindValue(":code", res);
return    query.exec();
}

bool fidelite:: modifierfidelite (int code,int points)
{
    QString res = QString :: number (code) ;
    QString res2 = QString :: number (points) ;
        QSqlQuery q;
         q.prepare("UPDATE carte_fidelite set CODE =:code,POINTS=:points where CODE=:code ");
         q.bindValue(":code",res);
        q.bindValue(":points",res2);





        return    q.exec();


}

QSqlQueryModel * fidelite::trie_points()
 { QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery(QString("SELECT * FROM carte_fidelite ORDER BY POINTS "));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("points "));


    return model;
 }


QSqlQueryModel * fidelite::chercher(int code )
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from carte_fidelite WHERE code=:code"));

     query.bindValue(":code",code);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("points"));


return model;
 }
