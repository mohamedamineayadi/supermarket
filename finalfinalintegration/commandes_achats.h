#ifndef COMMANDES_ACHATS_H
#define COMMANDES_ACHATS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>


class commandes_achats
{
public:
    commandes_achats();
     commandes_achats(QString,QString,int,QString);
     QString get_ref_cmd();
     QString get_date_cmd();
     int get_codefournisseur();
     QString get_idproduit();
     bool ajouter(int);
     void modifier();
     QSqlQueryModel * afficher();
     bool supprimer(QString);
     QSqlQueryModel * sort();
   private:
    QString ref_cmd;
    QString date_cmd;
    int codefournisseur;
    QString idproduit;
};

#endif // COMMANDES_ACHATS_H

