#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class client
{

    QString nom,prenom,sexe,mail;
    int id,tel;

public:
    client();
    client(int,QString,QString,QString,int,QString);
    QString get_nom();
    QString get_prenom();
    int get_id();
      int get_tel();
    QString get_sexe();
    QString get_mail();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifierclient(int,QString,QString,QString,int,QString);
    QSqlQueryModel * chercher(int);
     QSqlQueryModel *trie_nom();
};

#endif // CLIENT_H
