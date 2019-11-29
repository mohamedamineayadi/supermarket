#ifndef FIDELITE_H
#define FIDELITE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fidelite
{

    int code;
    int points;

public:
    fidelite();
    fidelite(int,int);
    int get_code();
    int get_points();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifierfidelite(int,int);
     QSqlQueryModel * chercher(int);
     QSqlQueryModel * trie_points();
};


#endif // FIDELITE_H
