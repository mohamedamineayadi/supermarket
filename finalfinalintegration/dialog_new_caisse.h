#ifndef DIALOG_NEW_CAISSE_H
#define DIALOG_NEW_CAISSE_H

#include <QDialog>

namespace Ui {
class Dialog_new_caisse;
}
class QSystemTrayIcon;
class Dialog_new_caisse : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_new_caisse(QWidget *parent = nullptr);
    ~Dialog_new_caisse();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog_new_caisse *ui;
    QSystemTrayIcon *mSystemTrayIcon;
};

#endif // DIALOG_NEW_CAISSE_H
