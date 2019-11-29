#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class personnel
{
public:
    personnel();
    personnel(int,QString,QString,QString,QString,int,QString,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    QString get_date_naissance();
    QString get_adresse();
    int get_salaire();
    QString get_service();
    QString get_statue();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString nom,prenom,date_naissance,adresse,service,statue;
    int id,salaire;
};

#endif // PERSONNEL_H


