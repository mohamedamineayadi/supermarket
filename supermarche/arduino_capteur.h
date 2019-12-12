#ifndef ARDUINO_CAPTEUR_H
#define ARDUINO_CAPTEUR_H
#include"arduino.h"

#include <QWidget>

namespace Ui {
class arduino_capteur;
}

class arduino_capteur : public QWidget
{
    Q_OBJECT

public:
    explicit arduino_capteur(QWidget *parent = nullptr);
    ~arduino_capteur();

private slots:
    void update_label();

    void on_des_bip_clicked();

    void on_activer_bip_clicked();

    void on_label_linkActivated(const QString &link);

    void on_pushButton_clicked();

private:
    Ui::arduino_capteur *ui;
    QByteArray data; // variable contenant les données reçues

    Arduino A;
};

#endif // ARDUINO_CAPTEUR_H

