#include "prodcat.h"
#include "ui_prodcat.h"
#include <QString>
#include "produit.h"
#include "categorie.h"
#include "stati.h"
#include <QMessageBox>
#include<QSystemTrayIcon>
prodcat::prodcat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::prodcat)
{
ui->setupUi(this);
ui->tabproduit->setModel(tmpproduit.afficher());
ui->tabcat->setModel(tmpcat.afficher());
mysystem= new QSystemTrayIcon(this);
mysystem->setIcon(QIcon(":/icon.png"));
mysystem->setVisible(true);
}

prodcat::~prodcat()
{
    delete ui;
}

void prodcat::on_pushButton_ajouter1_clicked()
{
    int id = ui->lineEdit_idprod->text().toInt();
    QString nom= ui->lineEdit_nomprod->text();
    int prix= ui->lineEdit_prix->text().toInt();
    QString categorie= ui->lineEdit_categorie->text();
    int cyclevie= ui->lineEdit_cyclevie->text().toInt();
    int code= ui->lineEdit_codebarre->text().toInt();
  produit e(id,nom,prix,categorie,cyclevie,code);
  bool test=e.ajouter();
  if(test)
{ui->tabproduit->setModel(tmpproduit.afficher());//refresh
      mysystem->showMessage(tr("Gestion Produits"),tr("Ajout d'un produit avec succes"));

      /*QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Produit ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);*/

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
void prodcat::on_pushButton_ajouter2_clicked()
{
    int idcat=ui->lineEdit_idcat->text().toInt();
    QString nomcat= ui->lineEdit_nomcat->text();
    categorie c(idcat,nomcat);
    bool test=c.ajouter();
    if(test)
  {ui->tabcat->setModel(tmpcat.afficher());//refresh
        mysystem->showMessage(tr("Gestion Categories"),tr("Ajout d'une categorie avec succes"));
  /*QMessageBox::information(nullptr, QObject::tr("Ajouter une categorie"),
                    QObject::tr("Categorie ajoutée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une categorie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
void prodcat::on_pushButton_supp2_clicked()
{
int idcat = ui->lineEdit_suppcat->text().toInt();
bool test=tmpcat.supprimer(idcat);
if(test)
{
        ui->tabcat->setModel(tmpcat.afficher());//refresh
         mysystem->showMessage(tr("Gestion Categories"),tr("Supression effectuée"));


}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une Categorie"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void prodcat::on_pushButton_supp1_clicked()
{
    int id=ui->lineEdit_suppnom->text().toInt();
        bool test=tmpproduit.supprimer(id);
        if(test)
        {
            ui->tabproduit->setModel(tmpproduit.afficher());//refresh
            mysystem->showMessage(tr("Gestion Produits"),tr("Supression effectuée"));
               /*QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                            QObject::tr("Champs vide.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);*/

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}
void prodcat::on_pushButton_modifier1_clicked()
{
    int id = ui->lineEdit_idprod->text().toInt();

        QString nom= ui->lineEdit_nomprod->text();

        int prix = ui->lineEdit_prix->text().toInt();

        QString categorie= ui->lineEdit_categorie->text();

         int cyclevie= ui->lineEdit_cyclevie->text().toInt();

         int code= ui->lineEdit_codebarre->text().toInt();

         bool test = tmpproduit.modifier(id,nom,prix,categorie,cyclevie,code);

                  if (test)

                  {

                       ui->tabproduit->setModel(tmpproduit.afficher());



                      QMessageBox::information(nullptr, QObject::tr("Modification avec sucées !"),

                                  QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

                  }

                  else

                      QMessageBox::critical(nullptr, QObject::tr("modifier non sucess !"),

                                  QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}

void prodcat::on_pushButton_modifier2_clicked()
{
    int idcat = ui->lineEdit_idcat->text().toInt();

        QString nomcat= ui->lineEdit_nomcat->text();
        bool test = tmpcat.modifier(idcat,nomcat);
        if (test)

        {

            ui->tabcat->setModel(tmpcat.afficher());


            QMessageBox::information(nullptr, QObject::tr("Modification avec sucées !"),

                        QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

        }

        else

            QMessageBox::critical(nullptr, QObject::tr("Modification non sucess !"),

                        QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

}



void prodcat::on_pushButton_recherche1_clicked()
{
    int id = ui->lineEdit_rechercheprod->text().toInt();

       produit test= tmpproduit.rechercher(id);

       if (test.get_id()==id)

             {
                     ui->tabproduit->setModel(tmpproduit.afficher_recherche(id));
              /*  mysystem->showMessage(tr("Recherche"),tr("Recherche d'un produit effectué"));

           QMessageBox::information(nullptr, QObject::tr("Rechercher un Produit"),

                           QObject::tr("Produit trouvé.\n"

                                       "Click Cancel to exit."),
QMessageBox::Cancel);
*/
      }
       else


       {

           QMessageBox::critical(nullptr, QObject::tr("Error !"),

           QObject::tr("Le Produit n'est pas disponible !.\n"

                        "Click Cancel to exit."), QMessageBox::Cancel);

       }

}

void prodcat::on_pushButton_trier1_clicked()
{
    ui->tabproduit->setModel(tmpproduit.afficherTri());
}

void prodcat::on_pushButton_trier2_clicked()
{
    ui->tabcat->setModel(tmpcat.afficherTri());
}

void prodcat::on_pushButton_recherche2_clicked()
{
    int idcat = ui->lineEdit_recherchecat->text().toInt();

       categorie test= tmpcat.rechercher(idcat);

       if (test.get_idcat()==idcat)

             { QMessageBox::critical(nullptr, QObject::tr("Error !"),

                                     QObject::tr("Categorie n'est pas disponible !.\n"

                                                  "Click Cancel to exit."), QMessageBox::Cancel);

           // mysystem->showMessage(tr("Recherche"),tr("Recherche d'un produit effectué"));

          /* QMessageBox::information(nullptr, QObject::tr("Rechercher un Produit"),

                           QObject::tr("Categorie trouvé.\n"

                                       "Click Cancel to exit."),
QMessageBox::Cancel);*/

             }

       else


       {  ui->tabcat->setModel(tmpcat.afficher_recherche(idcat));



}
}


/*void MainWindow::on_pushButton_16_clicked()
{
    stati s;
    s.exec();
}*/
