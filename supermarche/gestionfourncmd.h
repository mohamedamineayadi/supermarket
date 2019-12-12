#ifndef GESTIONFOURCMD_H
#define GESTIONFOURCMD_H

#include <QWidget>
#include "fournisseur.h"
#include"commandes_achats.h"

namespace Ui {
class Gestionfourcmd;
}

class Gestionfourcmd : public QWidget
{
    Q_OBJECT

public:
    explicit Gestionfourcmd(QWidget *parent = nullptr);
    ~Gestionfourcmd();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_ajouter_four_clicked();

    void on_pushButton_supprimer_fourn_clicked();

    void on_pushButton_chercher_clicked();

    void on_pushButton_modifier_fourn_clicked();

    void on_pushButton_actualiser_fourn_clicked();

    void on_pushButton_recherche_fourn_clicked();

    void on_pushButton_ajouter_cmd_clicked();

    void on_pushButton_supp_cmd_clicked();

    void on_pushButton_modifier_cmd_clicked();

    void on_pushButton_cherchercmd_clicked();

    void on_pushButton_actualisercmd_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_recherchecmd_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Gestionfourcmd *ui;
    Fournisseur tmpfournisseur;
    commandes_achats tmpcmd;
};

#endif // GESTIONFOURCMD_H

