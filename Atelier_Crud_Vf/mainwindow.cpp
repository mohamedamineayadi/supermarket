#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "fidelite.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
  ui->tabclient->setModel(tmpclient.afficher());
  ui->tabclient_2->setModel(tmpfidelite .afficher());//refresh

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString sexe= ui->lineEdit_nom->text();
    QString tel= ui->lineEdit_prenom->text();
    QString mail= ui->lineEdit_nom->text();

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

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
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



void MainWindow::on_pb_ajouter_2_clicked()
{
    int points = ui->lineEdit_points->text().toInt();
    int code= ui->lineEdit_code->text().toInt();


  fidelite e(points,code);
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


void MainWindow::on_pb_supprimer_2_clicked()
{
    int code = ui->lineEdit_code->text().toInt();
    bool test=tmpfidelite.supprimer(code);
    if(test)
    {ui->tabclient_2->setModel(tmpfidelite .afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{

    int code = ui->lineEdit->text().toInt();
    ui->tabclient_2->setModel(tmpfidelite.chercher(code));
}

void MainWindow::on_pushButton_2_clicked()
{

    int id = ui->lineEdit_id_3->text().toInt();
    ui->tabclient->setModel(tmpclient.chercher(id));
}


void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();

    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom_2->text();
     QString sexe= ui->lineEdit_sexe_2->text();
     QString mail= ui->lineEdit_mail_2->text();
     QString tel= ui->lineEdit_tel_2->text();

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




void MainWindow::on_pushButton_5_clicked()
{
     ui->tabclient->setModel(tmpclient.trie_nom());
}

void MainWindow::on_pushButton_4_clicked()
{
      ui->tabclient_2->setModel(tmpfidelite.trie_points());
}
