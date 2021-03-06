#include "dialog_update_caisse.h"
#include "ui_dialog_update_caisse.h"
#include "caissevente.h"

Dialog_update_caisse::Dialog_update_caisse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_update_caisse)
{
    ui->setupUi(this);
    mSystemTrayIcon = new QSystemTrayIcon;
    mSystemTrayIcon->setVisible(true);
    mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
}

Dialog_update_caisse::~Dialog_update_caisse()
{
    delete ui;
}

void Dialog_update_caisse::on_pushButton_clicked()
{
    int idcaisse=ui->lineEdit_idcaisse->text().toInt();
    int sd=ui->lineEdit_sd->text().toInt();
    bool test = tmpcaisse.ModifyCMD(idcaisse,sd);
    if (test)
    {
        mSystemTrayIcon->showMessage(tr("Notification!"),tr("Modification Done!"));
        QMessageBox::information(nullptr, QObject::tr("Modification Done!"),
                                 QObject::tr( "Click Ok to exit."), QMessageBox::Ok);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modification Failed!"),
                              QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}
