#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "cmdventes.h"
#include <QMessageBox>
#include <QtDebug>
#include <QDateTime>
#include <QSystemTrayIcon>
mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    mSystemTrayIcon = new QSystemTrayIcon;
    mSystemTrayIcon->setVisible(true);
    mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
    QDateTime dteNow = QDateTime::currentDateTime();
    ui->tableView_affichage->setModel(tmpcmd.afficher());
    ui->dateTimeEdit->setDateTime(dteNow);
    ui->dateTimeEdit_find->setDateTime(dteNow);
    ui->dateTimeEdit_update->setDateTime(dteNow);
    ui->statusbar->showMessage("Disconnected");
    ui->lineEdit__TVA->setEnabled(0);
    ui->lineEdit_PrixHT->setEnabled(0);
    ui->lineEdit_qty_add->setEnabled(0);
    ui->lineEdit_NetaPayer->setEnabled(0);
    ui->lineEdit_ClientFind->setEnabled(0);
    ui->lineEdit_qty_update->setEnabled(0);
    ui->lineEdit_clientname_add->setEnabled(0);
    ui->lineEdit_articlename_add->setEnabled(0);
    ui->lineEdit_clientname_update->setEnabled(0);
    ui->lineEdit_articlename_update->setEnabled(0);
    ui->dateTimeEdit_find->setEnabled(0);
    ui->dateTimeEdit_update->setEnabled(0);
    ui->pushButton_logout->setEnabled(0);
}

mainwindow::~mainwindow()
{
    delete ui;
}


void mainwindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void mainwindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

void mainwindow::on_actionConnexion_triggered()
{
    Connexion c;
    bool test=c.ouvrirConnexion();

    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("Database Connection"),
                    QObject::tr("Connection Done.\n"
                                "Click Ok to continue."), QMessageBox::Ok);
        ui->label_status->setText("<span style='font-style:bold; color:#00aa00;'>Connected</span></p>");
        ui->statusbar->showMessage("Connected");
        ui->tableView_affichage->setModel(tmpcmd.afficher());

    }
    else

        QMessageBox::critical(nullptr, QObject::tr("Database Connection"),
                    QObject::tr("Connection Failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}

void mainwindow::on_pushButton_affichage_clicked()
{
    ui->tableView_affichage->setModel(tmpcmd.afficher());
}

void mainwindow::on_actionDisconnect_triggered()
{
    Connexion c;
    c.fermerConnexion();
    QMessageBox::information(nullptr, QObject::tr("Database Connection"),
                QObject::tr("Disconnected.\n"
                            "Click Ok to continue."), QMessageBox::Ok);
    ui->label_status->setText("<span style='font-style:bold; color:red;'>Disconnected</span></p>");




}

void mainwindow::on_pushButton_addcmd_clicked()
{
    QString DATE_CMD,ID_CAISSE,ID_PRODUIT,ID_CLIENT,HEURE_CMD;
    int PRIX_CMDV = ui->lineEdit_PrixCMDV->text().toInt();
    int REFCMDV = ui->lineEdit_REFCMDV->text().toInt();
   /* QString DATE_CMD = ui->dateTimeEdit->dateTime().toString();*/
  cmdventes cmd(REFCMDV,DATE_CMD,ID_CAISSE,ID_PRODUIT,ID_CLIENT,HEURE_CMD,PRIX_CMDV);
  bool test=cmd.ajouter();
  if(test)
{
QMessageBox::information(nullptr, QObject::tr(nullptr),
                  QObject::tr("Commande ajoutée.\n"
                              "Click Ok to exit."), QMessageBox::Ok);

}
  else
      QMessageBox::critical(nullptr, QObject::tr(nullptr),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

ui->tableView_ajcmd->setModel(tmpcmd.afficher());//refresh
}

void mainwindow::on_pushButton_find_clicked()
{
    int REFCMDV = ui->lineEdit_refFind->text().toInt();

           cmdventes test= tmpcmd.FindExist(REFCMDV);

           if (test.GetREFCMDV()==REFCMDV)
           {
               ui->tableView_find_modify->setModel(tmpcmd.DisplayFind(REFCMDV));
               mSystemTrayIcon->showMessage(tr("Notification!"),tr("Attribus Exist!"));
           }


           else
           {

               QMessageBox::critical(nullptr, QObject::tr("Critical Error"),
               QObject::tr("La commande n'est pas disponible !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

           }
}

void mainwindow::on_pushButton_deletecmd_clicked()
{
    int REFCMDV = ui->lineEdit_refFind->text().toInt();
        bool test=tmpcmd.CancelCMD(REFCMDV);
        if(test)
        {
           mSystemTrayIcon->showMessage(tr("Notification!"),tr("Command Cancelation Done!"));
            QMessageBox::information(nullptr, QObject::tr("Annuler une commande"),
                        QObject::tr("Commande supprimée.\n"
                                    "Click Ok to exit."), QMessageBox::Ok);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Annuler une commande"),
                        QObject::tr("Erreur\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void mainwindow::on_pushButton_modifycmd_clicked()
{
    int REFCMDV=ui->lineEdit_refcmd_update->text().toInt();
    int PRIX_CMD=ui->lineEdit_prixcmdv_update->text().toInt();
    bool test = tmpcmd.ModifyCMD(REFCMDV,PRIX_CMD);
    if (test)
    {
        ui->tableView_find_modify->setModel(tmpcmd.DisplayFind(REFCMDV));
        mSystemTrayIcon->showMessage(tr("Notification!"),tr("Modification Done!"));
        QMessageBox::information(nullptr, QObject::tr("Modification Done!"),
                                 QObject::tr( "Click Ok to exit."), QMessageBox::Ok);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modification Failed!"),
                              QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}

void mainwindow::on_pushButton_sortAZ_clicked()
{
    ui->tableView_affichage->setModel(tmpcmd.sortAZ());
    mSystemTrayIcon->showMessage(tr("Notification!"),tr("Sort Done!"));
}

void mainwindow::on_pushButton_sortZA_clicked()
{
    ui->tableView_affichage->setModel(tmpcmd.sortZA());
    mSystemTrayIcon->showMessage(tr("Notification!"),tr("Sort Done!"));
}

void mainwindow::on_actionReport_for_a_bug_triggered()
{
    QMessageBox::information(nullptr, QObject::tr("Feedback"),
                             QObject::tr( "Contact us: <a href=mailto:cubix@esprit.tn'>cubix@esprit.tn</a>"), QMessageBox::Ok);
}
