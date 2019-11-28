#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
#include"commandes_achats.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    Fournisseur tmpfournisseur;
    commandes_achats tmpcmd;
};

#endif // MAINWINDOW_H
