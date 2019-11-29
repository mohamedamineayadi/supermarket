#ifndef CONGE_H
#define CONGE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class conge
{
public:
    conge();
    conge(int,int,int,int,int);
    int get_id_conge();
    int get_id();
    int get_nbr_conge();
    int get_debut_conge();
    int get_fin_conge();
    bool ajouter();
    QSqlQueryModel * afficher();
   bool supprimer(int);
   QSqlQueryModel * chercher(int);
   QSqlQueryModel *trie_conge();
    bool modifierconge(int,int,int,int,int);
private:
    int id_conge,id,nbr_conge,debut_conge,fin_conge;
};

#endif // CONGE_H
