#ifndef CLIENT_FIDELITE_H
#define CLIENT_FIDELITE_H
#include"client.h"
#include"fidelite.h"
#include <QWidget>

namespace Ui {
class client_fidelite;
}
class QSystemTrayIcon;

class client_fidelite : public QWidget
{
    Q_OBJECT

public:
    explicit client_fidelite(QWidget *parent = nullptr);
    ~client_fidelite();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_actualiser_clicked();

    void on_pushButton_recherche_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_modifier_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::client_fidelite *ui;
    client tmpclient;
    fidelite tmpfidelite;
    QSystemTrayIcon * mysystem ;

};

#endif // CLIENT_FIDELITE_H
