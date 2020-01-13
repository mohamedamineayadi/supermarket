#ifndef TAPIS_H
#define TAPIS_H
#include"arduino.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class tapis; }
QT_END_NAMESPACE

class tapis : public QWidget
{
    Q_OBJECT

public:
    tapis(QWidget *parent = nullptr);
    ~tapis();

private slots:
    void update_label();

    void on_activer_bip_clicked();

    void on_des_bip_clicked();



    //void on_pushButton_6_clicked();

private:
    Ui::tapis *ui;

    QByteArray data; // variable contenant les données reçues

    Arduino A;
};
#endif // TAPIS_H
