#ifndef FIDELITE_H
#define FIDELITE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fidelite
{

    int code;
    int points;
    int id;
public:
    fidelite();
    fidelite(int,int,int);
    int get_code();
    int get_points();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifierfidelite(int,int,int);
     QSqlQueryModel * chercher(int);
     QSqlQueryModel * trie_points();
};


#endif // FIDELITE_H
