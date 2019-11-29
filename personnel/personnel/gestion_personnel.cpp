#include "gestion_personnel.h"
#include "ui_gestion_personnel.h"

gestion_personnel::gestion_personnel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestion_personnel)
{
    ui->setupUi(this);
}

gestion_personnel::~gestion_personnel()
{
    delete ui;
}
