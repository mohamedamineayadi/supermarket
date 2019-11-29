#include "mainwindow.h"
#include "connexion.h"
#include <QtDebug>
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
        a.setStyle("fusion");
    mainwindow w;
    w.show();
    return a.exec();
}
