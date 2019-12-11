#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class produit
{
    class QSystemTrayIcon;
public:
    produit();
    produit(int,QString,int,QString,int,int);
        int get_id();
        QString get_nom();
        int get_prix();
        QString get_categorie();
        int get_cyclevie();
        int get_code();
        bool ajouter();
        bool modifier(int,QString,int,QString,int,int);
        QSqlQueryModel * afficher();
        QSqlQueryModel * afficherTri();
        QSqlQueryModel * afficher_recherche(int);
        bool supprimer(int);
        produit rechercher(int);
private:
        QString nom,categorie;
            int id,cyclevie,code,prix;
            QSystemTrayIcon * mysystem;
};

#endif // PRODUIT_H
