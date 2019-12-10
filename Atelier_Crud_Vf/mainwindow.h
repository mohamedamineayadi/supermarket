#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include "fidelite.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_lineEdit_id_cursorPositionChanged(int arg1, int arg2);

    void on_pb_ajouter_2_clicked();

    void on_tabWidget_3_currentChanged(int index);

    void on_pb_supprimer_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pushButton_3_clicked();




    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pb_modifier_4_clicked();

private:
    Ui::MainWindow *ui;
    client tmpclient;
    fidelite tmpfidelite;
     QSystemTrayIcon * mysystem;
};

#endif // MAINWINDOW_H
