#ifndef GESTION_PERSONNEL_H
#define GESTION_PERSONNEL_H

#include <QWidget>

namespace Ui {
class gestion_personnel;
}

class gestion_personnel : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_personnel(QWidget *parent = nullptr);
    ~gestion_personnel();

private:
    Ui::gestion_personnel *ui;
};

#endif // GESTION_PERSONNEL_H
