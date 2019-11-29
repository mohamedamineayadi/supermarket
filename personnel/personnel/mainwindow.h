#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "information.h"
#include "conge.h"
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

    void on_pb_ajouter_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    Information tmpinformation;
 conge tmpconge ;
 QSystemTrayIcon * mysystem;
};

#endif // MAINWINDOW_H
