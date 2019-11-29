#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class client
{

    QString nom,prenom,sexe,mail,tel;
    int id;

public:
    client();
    client(int,QString,QString,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_id();
    QString get_sexe();
    QString get_mail();
    QString get_tel();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifierclient(int,QString,QString,QString,QString,QString);
    QSqlQueryModel * chercher(int);
     QSqlQueryModel *trie_nom();
};

#endif // CLIENT_H
