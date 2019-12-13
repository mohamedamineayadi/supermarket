#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connexion c;
    bool test=c.ouvrirConnexion();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("Database Connection"),
                    QObject::tr("Connection Done.\n"
                                "Click Ok to continue."), QMessageBox::Ok);
}
else
        QMessageBox::critical(nullptr, QObject::tr("Database Connection"),
                    QObject::tr("Connection Failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}

