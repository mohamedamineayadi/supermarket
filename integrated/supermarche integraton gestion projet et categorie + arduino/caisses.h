#ifndef CAISSES_H
#define CAISSES_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>

class caisses
{
public:
    caisses();
    caisses(int ,int ,int);
    int GetID_CAISSE();
    QSortFilterProxyModel * afficher_caisses();
    QSqlQueryModel * DisplayFind_caisses(int);
    caisses FindExist_caisses(int);
    int Get_SOLDE_DEP();
    int Get_SOLDE_FINAL();
private:
    int ID_CAISSE,SOLDE_DEP,SOLDE_FINAL;
};

#endif // CAISSES_H
