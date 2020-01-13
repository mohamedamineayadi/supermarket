#ifndef INFORMATION_H
#define INFORMATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Information
{public:
    Information();
    Information(int,QString,QString,QString,QString,QString,QString,int,int,int,int);
    QString get_nom();
    QString get_prenom();
    QString get_sexe();
    QString get_etat();
    QString get_adresse();
    QString get_departement();
    int get_id();
    int get_salaire();
    int get_commision();
    int get_nbr_prs();
    int get_nbr_abs();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifierinformation(int,QString,QString,QString,QString,QString,QString,int,int,int,int);
    QSqlQueryModel * chercher(int);
    QSqlQueryModel *trie_information();
private:
    QString nom,prenom,sexe,etat,adresse,departement;
    int id,salaire,commision,nbr_prs,nbr_abs;
};

#endif // INFORMATION_H
