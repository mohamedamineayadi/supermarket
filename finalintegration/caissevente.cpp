#include "caissevente.h"

CaisseVente::CaisseVente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CaisseVente)
{
    ui->setupUi(this);
    ui->tableView_affichage->setSortingEnabled(true); // enable sortingEnabled
    ui->tableView_ajcmd->setSortingEnabled(true);
    ui->tableView_find_modify->setSortingEnabled(true);
    ui->tableView_displaycaisse->setSortingEnabled(true);
    mSystemTrayIcon = new QSystemTrayIcon;
    mSystemTrayIcon->setVisible(true);
    mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
    QDateTime dteNow = QDateTime::currentDateTime();
    ui->tableView_affichage->setModel(tmpcmd.afficher());
    ui->dateTimeEdit->setDateTime(dteNow);
    ui->dateTimeEdit_find->setDateTime(dteNow);
    ui->dateTimeEdit_update->setDateTime(dteNow);
    ui->statusbar->showMessage("Disconnected");

    ui->lineEdit_qty_add->setEnabled(0);

    ui->lineEdit_ClientFind->setEnabled(0);
    ui->lineEdit_qty_update->setEnabled(0);
    ui->lineEdit_clientname_add->setEnabled(0);
    ui->lineEdit_articlename_add->setEnabled(0);
    ui->lineEdit_clientname_update->setEnabled(0);
    ui->lineEdit_articlename_update->setEnabled(0);
    ui->dateTimeEdit_find->setEnabled(0);
    ui->dateTimeEdit_update->setEnabled(0);

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_CAISSE from CAISSES");
    ui->comboBox_select->setModel(model);
    QSqlQueryModel * model1= new QSqlQueryModel();
    model1->setQuery("select SOLD_DEP from caisses");

    ui->lcdNumber_soldetotal->display(100);

    ui->tableView_displaycaisse->setModel(tmpcaisse.afficher_caisses());

}

CaisseVente::~CaisseVente()
{
    delete ui;
}



void CaisseVente::on_pushButton_addcmd_clicked()
{
    QString ID_CAISSE,ID_PRODUIT,ID_CLIENT,HEURE_CMD;
    int PRIX_CMDV = ui->lineEdit_PrixCMDV->text().toInt();
    int REFCMDV = ui->lineEdit_REFCMDV->text().toInt();
   QString DATE_CMD = ui->dateTimeEdit->dateTime().toString();
  cmdventes cmd(REFCMDV,DATE_CMD,ID_CAISSE,ID_PRODUIT,ID_CLIENT,HEURE_CMD,PRIX_CMDV);
  bool test=cmd.ajouter();
  if(test)
{
      mSystemTrayIcon->showMessage(tr("Notification!"),tr("Commande ajoutée"));
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

void CaisseVente::on_pushButton_displaynewcmd_clicked()
{
    ui->tableView_ajcmd->setModel(tmpcmd.afficher());//refresh
}

void CaisseVente::on_pushButton_refresh_clicked()
{
    ui->tableView_affichage->setModel(tmpcmd.afficher());
}

void CaisseVente::on_pushButton_find_clicked()
{
    int REFCMDV = ui->lineEdit_refFind->text().toInt();

           cmdventes test= tmpcmd.FindExist(REFCMDV);

           if (test.GetREFCMDV()==REFCMDV)
           {
               ui->tableView_find_modify->setModel(tmpcmd.DisplayFind(REFCMDV));
               mSystemTrayIcon->showMessage(tr("Notification!"),tr("Element Exist!"));
           }


           else
           {

               QMessageBox::critical(nullptr, QObject::tr("Critical Error"),
               QObject::tr("La commande n'est pas disponible !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

           }
}

void CaisseVente::on_pushButton_deletecmd_clicked()
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

void CaisseVente::on_pushButton_modifycmd_clicked()
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

void CaisseVente::on_pushButton_cancelmodify_clicked()
{
    ui->lineEdit_refcmd_update->setText("");
    ui->lineEdit_prixcmdv_update->setText("");
}

void CaisseVente::on_comboBox_select_currentIndexChanged(int index)
{

}

void CaisseVente::on_pushButton_validerselect_clicked()
{

    int  idcaisse =ui->comboBox_select->currentText().toInt();


           caisses test= tmpcaisse.FindExist_caisses(idcaisse);

           if (test.GetID_CAISSE()==idcaisse)
           {
               ui->tableView_displaycaisse->setModel(tmpcaisse.DisplayFind_caisses(idcaisse));
               mSystemTrayIcon->showMessage(tr("Notification!"),tr("Element Exist!"));
           }


           else
           {

               QMessageBox::critical(nullptr, QObject::tr("Critical Error"),
               QObject::tr("La commande n'est pas disponible !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

           }
}

void CaisseVente::on_pushButton_addcaisse_clicked()
{
    ac = new Dialog_new_caisse(this);
    ac->show();
}

void CaisseVente::on_pushButton_refreshcaisse_clicked()
{
    ui->tableView_displaycaisse->setModel(tmpcaisse.afficher_caisses());
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_CAISSE from CAISSES");
    ui->comboBox_select->setModel(model);
}

void CaisseVente::on_pushButton_majcaisse_clicked()
{
    upc = new Dialog_update_caisse(this);
    upc->show();
}

void CaisseVente::on_pushButton_quitter_clicked()
{
    hide();
}

void CaisseVente::on_pushButton_quitter_2_clicked()
{
    hide();
}

void CaisseVente::on_pushButton_quitter_3_clicked()
{
    hide();
}
