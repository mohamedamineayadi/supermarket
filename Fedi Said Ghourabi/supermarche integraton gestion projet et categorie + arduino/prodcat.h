#ifndef PRODCAT_H
#define PRODCAT_H
#include "produit.h"
#include "categorie.h"
#include <QWidget>
#include "tapis.h"
namespace Ui {

class prodcat;
}
class QSystemTrayIcon;

class prodcat : public QWidget
{
    Q_OBJECT
public:
    explicit prodcat(QWidget *parent = nullptr);
    ~prodcat();

private slots:
    void on_pushButton_ajouter1_clicked();
    void on_pushButton_ajouter2_clicked();
    void on_pushButton_modifier1_clicked();
    void on_pushButton_modifier2_clicked();
    void on_pushButton_supp1_clicked();
    void on_pushButton_supp2_clicked();

    void on_pushButton_trier1_clicked();

    void on_pushButton_trier2_clicked();

    void on_pushButton_recherche1_clicked();

    void on_pushButton_recherche2_clicked();



    void on_pushButton_3_clicked();

    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::prodcat *ui;
    produit tmpproduit;
    categorie tmpcat;
    tapis *ta;
    QSystemTrayIcon * mysystem;


};

#endif // PRODCAT_H

