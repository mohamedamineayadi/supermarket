#ifndef CMDVENTES_H
#define CMDVENTES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>

class cmdventes
{
public:
    cmdventes();
    cmdventes(int ,QString ,QString ,QString , QString , QString, int);
    int GetREFCMDV();
    QString GetDATE_CMD();
    QString GetID_CAISSE();
    QString GetID_PRODUIT();
    QString GetID_CLIENT();
    QString GetHEURE_CMD();
    int GetPRIX_CMDV();
    QSortFilterProxyModel * afficher();
    QSortFilterProxyModel * afficher_caisses();
    bool ajouter();
    QSqlQueryModel * DisplayFind(int);
    QSqlQueryModel * sortAZ();
    QSqlQueryModel * sortZA();
    cmdventes FindExist(int);
    bool CancelCMD(int);
    bool ModifyCMD(int,int);
private:
    QString DATE_CMD,ID_CAISSE,ID_PRODUIT,ID_CLIENT,HEURE_CMD;
    int REFCMDV,PRIX_CMDV;
};



#endif // CMDVENTES_H
