#ifndef PRODCAT_H
#define PRODCAT_H
#include "produit.h"
#include "categorie.h"
#include <QMainWindow>
#include <QSystemTrayIcon>
namespace Ui {

class prodcat;
}
class QSystemTrayIcon;

class prodcat : public QMainWindow
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



private:
    Ui::prodcat *ui;
    produit tmpproduit;
    categorie tmpcat;
    QSystemTrayIcon * mysystem;


};

#endif // PRODCAT_H

