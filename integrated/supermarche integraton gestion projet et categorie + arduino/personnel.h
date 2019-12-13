#ifndef PERSONNEL_H
#define PERSONNEL_H
#include"information.h"
#include"conge.h"
#include <QWidget>

namespace Ui {
class personnel;
}
class QSystemTrayIcon;

class personnel : public QWidget
{
    Q_OBJECT

public:
    explicit personnel(QWidget *parent = nullptr);
    ~personnel();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_recherche_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_actualiser_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_modifier_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::personnel *ui;
    Information tmpinformation;
    conge tmpconge;

    QSystemTrayIcon * mysystem;

};

#endif // PERSONNEL_H
