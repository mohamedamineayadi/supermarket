#ifndef CAISSEVENTE_H
#define CAISSEVENTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QMainWindow>
#include "cmdventes.h"
#include "caisses.h"

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

private:
    Ui::CaisseVente *ui;
   cmdventes tmpcmd;
    caisses tmpcaisse;
    QSystemTrayIcon *mSystemTrayIcon;

};

#endif // CAISSEVENTE_H

