/*#include "stati.h"
#include "ui_stati.h"

stati::stati(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stati)
{
    ui->setupUi(this);
}

stati::~stati()
{
    delete ui;
}


int stati::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from Produit where prix BETWEEN '1' AND '10'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int stati::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from produit where prix BETWEEN '10' AND '50'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int stati::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from produit where prix BETWEEN '50' AND '100'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void stati::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    cout<<b<<endl ;
    int c=Statistique_partie3();
    cout<<c<<endl ;
    int d=Statistique_partie4();
    cout<<d<<endl ;

        float s2= b*100 ;
        float s3=c*100;

        float nb = b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;


        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
    QRectF size=QRectF(275,50,this->width()-600,this->width()-600);

    painter.setBrush(Qt::green);
    painter.drawPie(size,0,16*y);
    ui->label_200->setText("1-5") ;
    painter.setBrush(Qt::blue);
    painter.drawPie(size,16*y,16*m);
    ui->label_300->setText("10-50") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("50-100") ;

}

void stati::on_pushButton_100_clicked()
{
    hide();
}
*/
