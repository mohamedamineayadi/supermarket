#include "caisses.h"
#include <QDebug>


caisses::caisses()
{

    ID_CAISSE=0;
    SOLDE_DEP=0;
    SOLDE_FINAL=0;

}
caisses::caisses(int ID_CAISSE,int SOLDE_DEP, int SOLDE_FINAL)
{
    this->ID_CAISSE=ID_CAISSE;
    this->SOLDE_DEP=SOLDE_DEP;
    this->SOLDE_FINAL=SOLDE_FINAL;
}

int caisses::Get_SOLDE_DEP(){return SOLDE_DEP;}
int caisses::Get_SOLDE_FINAL(){return SOLDE_FINAL;}
int caisses::GetID_CAISSE(){return  ID_CAISSE;}

QSortFilterProxyModel * caisses::afficher_caisses()
{
QSqlQueryModel * _model= new QSqlQueryModel();
QSqlQuery query;
query.prepare("select ID_CAISSE, SOLDE_DEP,SOLDE_FINAL from CAISSES");
query.exec();
_model->setQuery(query);
_model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
_model->setHeaderData(1, Qt::Horizontal, QObject::tr("SOLDE DEPART"));
_model->setHeaderData(2, Qt::Horizontal, QObject::tr("SOLDE ARRIVE"));
QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(_model); // create proxy
proxyModel->setSourceModel(_model);
    return proxyModel;
}

QSqlQueryModel * caisses::DisplayFind_caisses(int ref)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare(QString("select ID_CAISSE, SOLDE_DEP,SOLDE_FINAL from CAISSES where ID_CAISSE=:ref"));
    q.bindValue(":ref",ref);
    q.exec();
    model->setQuery(q);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SOLDE DEPART"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SOLDE FINAL"));
    return model;
}

caisses caisses::FindExist_caisses(int ID_CAISSE)
{
     caisses *cmdv= new caisses();
      QSqlQuery q;
      q.prepare("SELECT * FROM CAISSES WHERE ID_CAISSE=?");
      q.addBindValue(ID_CAISSE);
      q.exec();
      if(q.next())
      {
      int ID_CAISSE = q.value(0).toInt();
      int SOLDE_DEP = q.value(1).toInt();
     int SOLDE_FINAL = q.value(2).toInt();
caisses(ID_CAISSE,SOLDE_DEP,SOLDE_FINAL);
  cmdv= new caisses(ID_CAISSE,SOLDE_DEP,SOLDE_FINAL);

  return *cmdv;
      }

      return *cmdv;
 }

