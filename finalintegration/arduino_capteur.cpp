#include "arduino_capteur.h"
#include "ui_arduino_capteur.h"
 // #include <iostream>
arduino_capteur::arduino_capteur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::arduino_capteur)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}

arduino_capteur::~arduino_capteur()
{
    delete ui;
}
void arduino_capteur::update_label()
{
    data=A.read_from_arduino();


    ui->label->setText(data);

  //  std::cout<<"label"<<ui->label->text().toStdString() << std::endl;


   /* if(data=="1")
    {

       // nbre++;

        ui->label_msg->setText(data); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher msg
//
        //QString compteur=QString::number(nbre);
       // ui->label_msg_2->setText(compteur);
    }

    else if (data=="0")

        ui->label_msg->setText("il n'y a pas de client");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher msg*/


}

void arduino_capteur::on_des_bip_clicked()
{
     A.write_to_arduino("0");
}

void arduino_capteur::on_activer_bip_clicked()
{
     A.write_to_arduino("1");
}



void arduino_capteur::on_pushButton_clicked()
{
     hide() ;
}
