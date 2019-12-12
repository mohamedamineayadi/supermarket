#include "produit.h"

produit::produit()
{
    id=0;
    nom="none";
    prix=0;
    categorie="none";
    cyclevie=0;
    code=0;
}
produit::produit(int id,QString nom,int prix,QString categorie,int cyclevie,int code)
{
  this->id=id;
  this->nom=nom;
  this->prix=prix;
  this->categorie=categorie;
  this->cyclevie=cyclevie;
  this->code=code;
}

int produit::get_id(){return  id;}
QString produit::get_nom(){return  nom;}
int produit::get_prix(){return prix;}
QString produit::get_categorie(){return categorie;}
int produit::get_cyclevie(){return cyclevie;}
int produit::get_code(){return code;}

bool produit::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO produit (ID, NOM, PRIX, CATEGORIE, CYCLEVIE, CODE) "
                    "VALUES (:id, :nom, :prix, :categorie, :cyclevie, :code)");
query.bindValue(":id", id);
query.bindValue(":nom", nom);
query.bindValue(":prix", prix);
query.bindValue(":categorie", categorie);
query.bindValue(":cyclevie", cyclevie);
query.bindValue(":code", code);

return    query.exec();
}
bool produit::modifier(int id,QString nom,int prix,QString categorie,int cyclevie,int code)
{


        QSqlQuery query;
        query.prepare("UPDATE PRODUIT set NOM=:nom , PRIX= :prix,CATEGORIE=:categorie,CYCLEVIE=:cyclevie,CODE= :code where ID=:id");
        query.bindValue(":id",id);
        query.bindValue(":nom",nom);
        query.bindValue(":prix",prix);
        query.bindValue(":categorie",categorie);
        query.bindValue(":cyclevie",cyclevie);
        query.bindValue(":code",code);

        return    query.exec();


}
QSqlQueryModel * produit::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PRODUIT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Categorie"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Cycle de vie"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Code"));
    return model;
}
QSqlQueryModel * produit::afficherTri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PRODUIT order by ID asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Categorie"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Cycle de vie"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Code"));
    return model;
}
QSqlQueryModel * produit::afficher_recherche(int ref)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare(QString("select * from PRODUIT where ID=:ref"));
    q.bindValue(":ref",ref);
    q.exec();
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Categorie"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Cycle de vie"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Code"));
    return model;
}

bool produit::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from produit where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

produit produit::rechercher(int id)
{
produit *prod= new produit();

      QSqlQuery q;

      q.prepare("SELECT * FROM PRODUIT WHERE id=?");
      q.addBindValue(id);
      q.exec();
      if(q.next())
      {
      int id = q.value(0).toInt();
      QString nom = q.value(1).toString();
      int prix = q.value(2).toInt();
      QString categorie = q.value(3).toString();
     int cyclevie = q.value(4).toInt();
     int code = q.value(5).toInt();

  prod= new produit(id,nom,prix,categorie,cyclevie,code);

  return *prod;
      }

      return *prod;
 }

