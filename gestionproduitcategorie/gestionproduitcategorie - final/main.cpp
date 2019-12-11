#include "prodcat.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QtDebug>

int main(int argc, char *argv[])
{  QApplication a(argc, argv);
    a.setStyle("fusion");
    Connexion c;

  bool test=c.ouvrirConnexion();
  prodcat w;
  if(test)
  {w.show();

      QMessageBox::information(nullptr, QObject::tr("Database is opened"),
                  QObject::tr("Connection avec succés.\n"
                              "Click Cancel to continue."), QMessageBox::Cancel);

  }
  else
      QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                  QObject::tr("Connection failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();}
