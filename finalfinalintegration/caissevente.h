#ifndef CAISSEVENTE_H
#define CAISSEVENTE_H
#include <QtDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QDateTime>
#include <QSystemTrayIcon>
#include "cmdventes.h"
#include "dialog_new_caisse.h"
#include "caisses.h"
#include "ui_caissevente.h"
#include "dialog_update_caisse.h"

namespace Ui {
class CaisseVente;
}
class QSystemTrayIcon;
class CaisseVente : public QMainWindow
{
    Q_OBJECT

public:
    explicit CaisseVente(QWidget *parent = nullptr);
    ~CaisseVente();


private slots:
    void on_pushButton_addcmd_clicked();

    void on_pushButton_displaynewcmd_clicked();

    void on_pushButton_refresh_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_deletecmd_clicked();

    void on_pushButton_modifycmd_clicked();

    void on_pushButton_cancelmodify_clicked();

    void on_comboBox_select_currentIndexChanged(int index);

    void on_pushButton_validerselect_clicked();

    void on_pushButton_addcaisse_clicked();

    void on_pushButton_refreshcaisse_clicked();

    void on_pushButton_majcaisse_clicked();

    void on_pushButton_quitter_clicked();

    void on_pushButton_quitter_2_clicked();

    void on_pushButton_quitter_3_clicked();

private:
    Ui::CaisseVente *ui;
   cmdventes tmpcmd;
    caisses tmpcaisse;
    QSystemTrayIcon *mSystemTrayIcon;
    Dialog_new_caisse *ac;
    Dialog_update_caisse *upc;


};

#endif // CAISSEVENTE_H

