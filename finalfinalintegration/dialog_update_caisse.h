#ifndef DIALOG_UPDATE_CAISSE_H
#define DIALOG_UPDATE_CAISSE_H

#include <QDialog>
#include "caisses.h"
namespace Ui {
class Dialog_update_caisse;
}
class QSystemTrayIcon;
class Dialog_update_caisse : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_update_caisse(QWidget *parent = nullptr);
    ~Dialog_update_caisse();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_update_caisse *ui;
    QSystemTrayIcon *mSystemTrayIcon;
    caisses tmpcaisse;
};

#endif // DIALOG_UPDATE_CAISSE_H
