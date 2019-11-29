#ifndef CONNEXION_H
#define CONNEXION_H

#include <QMainWindow>
#include <QSqlDatabase>

class Connexion
{
private:
    QSqlDatabase db;
public:
    Connexion();
    bool ouvrirConnexion();
    void fermerConnexion();

};

#endif // CONNEXION_H
