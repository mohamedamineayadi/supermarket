#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cmdventes.h"
QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class QSystemTrayIcon;

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

private slots:
    void on_actionExit_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionConnexion_triggered();

    void on_pushButton_affichage_clicked();

    void on_actionDisconnect_triggered();

    void on_pushButton_addcmd_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_deletecmd_clicked();

    void on_pushButton_modifycmd_clicked();

    void on_pushButton_sortAZ_clicked();

    void on_pushButton_sortZA_clicked();

    void on_actionReport_for_a_bug_triggered();

private:
    Ui::mainwindow *ui;
    cmdventes tmpcmd;
    QSystemTrayIcon *mSystemTrayIcon;

};
#endif // MAINWINDOW_H
