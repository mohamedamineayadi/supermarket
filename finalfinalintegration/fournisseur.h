#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
    #include <QString>
    #include <QSqlQuery>
    #include <QSqlQueryModel>
class Fournisseur
{public:
    Fournisseur();
    Fournisseur(int,QString,QString,QString,int,int);
    QString get_nom();
    QString get_adresse();
    QString get_email();
    int get_codefournisseur();
    int get_teleph();
    int get_fax();
    bool ajouter();
    void modifier();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString nom,adresse,email;
    int codefournisseur,fax,teleph;
};

#endif // FOURNISSEUR_H
