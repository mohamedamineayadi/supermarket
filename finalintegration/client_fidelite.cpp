#include "client_fidelite.h"
#include "ui_client_fidelite.h"
#include"client.h"
#include"fidelite.h"
#include <QMessageBox>
#include <QSystemTrayIcon>

client_fidelite::client_fidelite(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client_fidelite)
{
    mysystem=new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);

    ui->setupUi(this);
}

client_fidelite::~client_fidelite()
{
    delete ui;
}

void client_fidelite::on_pushButton_ajouter_clicked()
{
    mysystem->showMessage(tr("Notification"),tr("Le client a été ajouté"));

    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString sexe= ui->lineEdit_sexe->text();
      int tel = ui->lineEdit_tel->text().toInt();
    QString mail= ui->lineEdit_mail->text();

  client e(id,nom,prenom,sexe,tel,mail);
  bool test=e.ajouter();
  if(test)
{   ui->tabclient->setModel(tmpclient.afficher());//refresh

QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void client_fidelite::on_pushButton_modifier_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString sexe= ui->lineEdit_sexe->text();
    int tel = ui->lineEdit_tel->text().toInt();
    QString mail= ui->lineEdit_mail->text();

     bool test = tmpclient.modifierclient(id,nom,prenom,sexe,tel,mail);
         if (test)
         {
              ui->tabclient->setModel( tmpclient.afficher());

             QMessageBox::information(nullptr, QObject::tr("modifier avec sucess !"),
                         QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
         }
         else
             QMessageBox::critical(nullptr, QObject::tr("modifier non sucess !"),
                         QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}

void client_fidelite::on_pushButton_actualiser_clicked()
{
    ui->tabclient->setModel( tmpclient.afficher());


}

void client_fidelite::on_pushButton_recherche_clicked()
{
    int id = ui->lineEdit_recherche->text().toInt();
    ui->tabclient->setModel(tmpclient.chercher(id));
}

void client_fidelite::on_pushButton_tri_clicked()
{
      ui->tabclient->setModel(tmpclient.trie_nom());
}

void client_fidelite::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_supprimer->text().toInt();
    bool test=tmpclient.supprimer(id);
    if(test)
    {ui->tabclient->setModel(tmpclient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void client_fidelite::on_pushButton_ajouter_2_clicked()
{
    mysystem->showMessage(tr("Notification"),tr("Le client fidele a été ajouté"));

    int idf = ui->lineEdit_id_fidelite->text().toInt();
    int code = ui->lineEdit_code->text().toInt();
int points = ui->lineEdit_point->text().toInt();



  fidelite e(code,points,idf);
  bool test=e.ajouter();
  if(test)
{   ui->tabclient_2->setModel(tmpfidelite.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void client_fidelite::on_pushButton_modifier_2_clicked()
{
    int id = ui->lineEdit_id_fidelite->text().toInt();
    int code = ui->lineEdit_code->text().toInt();
int points = ui->lineEdit_point->text().toInt();


     bool test = tmpfidelite.modifierfidelite(id,code,points);
         if (test)
         {
              ui->tabclient_2->setModel( tmpfidelite.afficher());

             QMessageBox::information(nullptr, QObject::tr("modifier avec sucess !"),
                         QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
         }
         else
             QMessageBox::critical(nullptr, QObject::tr("modifier non sucess !"),
                         QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}

void client_fidelite::on_pushButton_4_clicked()
{
    ui->tabclient_2->setModel( tmpfidelite.afficher());
}

void client_fidelite::on_pushButton_6_clicked()
{
    int code = ui->lineEdit_recherche_2->text().toInt();
    ui->tabclient_2->setModel(tmpfidelite.chercher(code));
}

void client_fidelite::on_pushButton_5_clicked()
{
      ui->tabclient_2->setModel(tmpfidelite.trie_points());
}

void client_fidelite::on_pushButton_clicked()
{
    int code=ui->lineEdit_id_fidelite_2->text().toInt();
    bool test=tmpfidelite.supprimer(code);
    if(test)
    {   ui->tabclient_2->setModel(tmpfidelite .afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une carte_fidelite"),
                    QObject::tr("carte_fidelite supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une carte_fidelite"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void client_fidelite::on_pushButton_3_clicked()
{
    hide() ;
}

void client_fidelite::on_pushButton_2_clicked()
{
    hide() ;
}
