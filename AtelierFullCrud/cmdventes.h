#ifndef CMDVENTES_H
#define CMDVENTES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

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
    QSqlQueryModel * afficher();
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

