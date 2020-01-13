#ifndef CATEGORIE_H
#define CATEGORIE_H
#include <QString>
#include <QSqlQueryModel>

class categorie
{
public:
    categorie();
    categorie(int,QString);
        int get_idcat();
        QString get_nomcat();
        bool ajouter();
        QSqlQueryModel * afficher();
        QSqlQueryModel * afficherTri();
        QSqlQueryModel * afficher_recherche(int);
        bool supprimer(int);
        bool modifier(int,QString);
        categorie rechercher(int);
private:
        QString nomcat;
            int idcat;
};

#endif // CATEGORIE_H
