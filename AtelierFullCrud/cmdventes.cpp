#include <QDebug>
#include "cmdventes.h"

cmdventes::cmdventes()
{
    REFCMDV=0;
    DATE_CMD="";
    ID_CAISSE="";
    ID_PRODUIT="";
    ID_CLIENT="";
    HEURE_CMD="";
    PRIX_CMDV=0;
}
cmdventes::cmdventes(int REFCMDV,QString DATE_CMD,QString ID_CAISSE,QString ID_PRODUIT, QString ID_CLIENT, QString HEURE_CMD, int PRIX_CMDV)
{
    this->REFCMDV=REFCMDV;
    this->DATE_CMD=DATE_CMD;
    this->ID_CAISSE=ID_CAISSE;
    this->ID_PRODUIT=ID_PRODUIT;
    this->ID_CLIENT=ID_CLIENT;
    this->HEURE_CMD=HEURE_CMD;
    this->PRIX_CMDV=PRIX_CMDV;

}
int cmdventes::GetREFCMDV(){return  REFCMDV;}
QString cmdventes::GetDATE_CMD(){return DATE_CMD;}
QString cmdventes::GetID_CAISSE(){return  ID_CAISSE;}
QString cmdventes::GetID_CLIENT(){return  ID_CLIENT;}
QString cmdventes::GetID_PRODUIT(){return  ID_PRODUIT;}
QString cmdventes::GetHEURE_CMD(){return  HEURE_CMD;}
int cmdventes::GetPRIX_CMDV(){return PRIX_CMDV;}

QSqlQueryModel * cmdventes::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
query.prepare("select DATE_CMD, REFCMDV,PRIX_CMDV from CMDVENTES");
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("DATE/HEURE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("REFERENCE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    return model;
}

bool cmdventes::ajouter()
{
QSqlQuery query;
QString PCMDV= QString::number(PRIX_CMDV);
QString RCMDV= QString::number(REFCMDV);
query.prepare("INSERT INTO CMDVENTES (REFCMDV, DATE_CMD, ID_CLIENT, ID_CAISSE, ID_PRODUIT, HEURE_CMD, PRIX_CMDV) "
                    "VALUES (:REFCMDV, TO_DATE('2019-11-29','YYYY-MM-DD'), '1', '1','1', '0', :PRIX_CMDV)");

query.bindValue(":REFCMDV", RCMDV);
query.bindValue(":PRIX_CMDV", PCMDV);
return    query.exec();
}

QSqlQueryModel * cmdventes::sortAZ()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select DATE_CMD, REFCMDV,PRIX_CMDV from CMDVENTES order by REFCMDV asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("DATE/HEURE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("REFERENCE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    return model;
}

QSqlQueryModel * cmdventes::sortZA()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select DATE_CMD, REFCMDV,PRIX_CMDV from CMDVENTES order by REFCMDV DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("DATE/HEURE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model;
}
QSqlQueryModel * cmdventes::DisplayFind(int ref)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare(QString("select DATE_CMD, REFCMDV,PRIX_CMDV from CMDVENTES where REFCMDV=:ref"));
    q.bindValue(":ref",ref);
    q.exec();
    model->setQuery(q);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("DATE/HEURE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    return model;
}

cmdventes cmdventes::FindExist(int REFCMDV)
{
     cmdventes *cmdv= new cmdventes();
      QSqlQuery q;
      q.prepare("SELECT * FROM CMDVENTES WHERE REFCMDV=?");
      q.addBindValue(REFCMDV);
      q.exec();
      if(q.next())
      {
      int REFCMDV = q.value(0).toInt();
      QString DATE_CMD = q.value(1).toString();
      QString ID_CLIENT = q.value(2).toString();
      QString ID_CAISSE = q.value(3).toString();
     QString ID_PRODUIT = q.value(4).toString();
     QString HEURE_CMD = q.value(5).toString();
     int PRIX_CMDV = q.value(6).toInt();
cmdventes(REFCMDV,DATE_CMD,ID_CAISSE,ID_PRODUIT,ID_CLIENT,HEURE_CMD,PRIX_CMDV);
  cmdv= new cmdventes(REFCMDV,DATE_CMD,ID_CAISSE,ID_PRODUIT,ID_CLIENT,HEURE_CMD,PRIX_CMDV);

  return *cmdv;
      }

      return *cmdv;
 }

bool cmdventes::CancelCMD(int ref)
{
QSqlQuery query;
QString res= QString::number(ref);
query.prepare("DELETE FROM CMDVENTES WHERE REFCMDV= :ref ");
query.bindValue(":ref", res);
return    query.exec();
}

bool cmdventes::ModifyCMD(int REFCMDV, int PRIX_CMDV)
{
        QSqlQuery query;
        query.prepare("UPDATE CMDVENTES SET PRIX_CMDV= :PRIX_CMDV WHERE REFCMDV=:REFCMDV");
        query.bindValue(":REFCMDV", REFCMDV);
        query.bindValue(":PRIX_CMDV",PRIX_CMDV);
        return    query.exec();


}
