#include "conge.h"
#include <QDebug>
conge::conge()
{
id_conge=0;
id=0;
nbr_conge=0;
debut_conge=0;
fin_conge=0;
}

conge::conge(int id_conge,int id,int nbr_conge,int debut_conge,int fin_conge)
{
     this->id_conge=id_conge;
    this->id=id;
    this->nbr_conge=nbr_conge;
    this->debut_conge=debut_conge;
    this->fin_conge=fin_conge;
}
int conge::get_id_conge(){return  id_conge;}
int conge::get_id(){return  id;}
int conge::get_nbr_conge(){return  nbr_conge;}
int conge::get_debut_conge(){return  debut_conge;}
int conge::get_fin_conge(){return  fin_conge;}

bool conge::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString res1= QString::number(nbr_conge);
QString res2= QString::number(debut_conge);
QString res3= QString::number(fin_conge);
QString res4= QString::number(id_conge);
query.prepare("INSERT INTO conge (ID_CONGE, ID, NBR_CONGE, DEBUT_CONGE, FIN_CONGE) "
                    "VALUES ( :id_conge, :id, :nbr_conge, :debut_conge, :fin_conge)");
query.bindValue(":id_conge", res4);
query.bindValue(":id", res);
query.bindValue(":nbr_conge", res1);
query.bindValue(":debut_conge", res2);
query.bindValue(":fin_conge", res3);



return    query.exec();
}
QSqlQueryModel * conge::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from conge");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant du conge"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre de jour de conge "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Debut conge"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Fin conge"));

    return model;
}

bool conge::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from conge where ID_CONGE = :id_conge ");
query.bindValue(":id_conge",res);
return    query.exec();
}

QSqlQueryModel * conge::chercher(int id)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from conge WHERE ID_CONGE=:id"));

     query.bindValue(":id",id);

      query.exec();
     model->setQuery(query);

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant du conge"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Identifiant"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre de jour de conge "));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Debut conge"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Fin conge"));

return model;
 }

QSqlQueryModel * conge::trie_conge()
 { QSqlQueryModel * model = new QSqlQueryModel();

   model->setQuery(QString("select * from conge order by ID asc "));
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant du conge"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Identifiant"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre de jour de conge "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Debut conge"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("Fin conge"));



    return model;
 }
bool conge::modifierconge(int id_conge,int id,int nbr_conge,int debut_conge,int fin_conge)
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(nbr_conge);
    QString res2= QString::number(debut_conge);
    QString res3= QString::number(fin_conge);
    QString res4= QString::number(id_conge);
    query.prepare("UPDATE conge set ID_CONGE=:id_conge, ID=:id, NBR_CONGE=:nbr_conge, DEBUT_CONGE=:debut_conge, FIN_CONGE=:fin_conge where ID_CONGE=:id_conge") ;

    query.bindValue(":id_conge", res4);
    query.bindValue(":id", res);
    query.bindValue(":nbr_conge", res1);
    query.bindValue(":debut_conge", res2);
    query.bindValue(":fin_conge", res3);

        return    query.exec();


}
