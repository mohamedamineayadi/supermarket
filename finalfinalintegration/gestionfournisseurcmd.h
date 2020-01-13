#ifndef GESTIONFOURNISSEURCMD_H
#define GESTIONFOURNISSEURCMD_H

#include <QWidget>
#include "fournisseur.h"
#include"commandes_achats.h"
#include <QWidget>
#include "arduinoo.h"
namespace Ui {
class GestionFournisseurCmd;
}

class GestionFournisseurCmd : public QWidget
{
    Q_OBJECT

public:
    explicit GestionFournisseurCmd(QWidget *parent = nullptr);
    ~GestionFournisseurCmd();

private slots:

    void on_pb_ajouter_fourn_clicked();

    void on_pb_supprimer_fourn_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_ok_modifier_clicked();

    void on_pushButton_actualiser_clicked();

    void on_pb_recherche_fourn_clicked();

    void on_pushButton_ajoutcmd_clicked();

    void on_pushButton_suppcmd_clicked();

    void on_pushButton_modifiercmd_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_cherchercmd_clicked();

    void on_pushButton_actualisercmd_clicked();

    void on_pushButton_triercmd_clicked();



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_quitt_clicked();

private:
    Ui::GestionFournisseurCmd *ui;
    Fournisseur tmpfournisseur;
    commandes_achats tmpcmd;
    arduinoo * a;
};


#endif // GESTIONFOURNISSEURCMD_H
