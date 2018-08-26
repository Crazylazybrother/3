#include "nuinquire.h"
#include "ui_nuinquire.h"
#include <QItemSelectionModel>
#include "mainwindow.h"

extern struct Student st[50000];

extern qint16 t;

NUInquire::NUInquire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NUInquire)
{
    ui->setupUi(this);
}

NUInquire::~NUInquire()
{
    delete ui;
}

void NUInquire::on_pushButton_clicked()
{
     QString snumber= ui->lineEdit->text();
     ui->textBrowser->clear();

     QString b="姓名             学号             宿舍";
     ui->textBrowser->append(b);

     QString name;
     QString number;
     QString sdnumber;

     for (int i = 1; i<t; i++)
     {
         for (int j = i; j<t; j++)
         {
             if (st[i].number>st[j].number)
             {
                 name= st[i].name;
                 number= st[i].number;
                 sdnumber = st[i].dnumber;

                 st[i].name= st[j].name;
                 st[i].number= st[j].number;
                 st[i].dnumber= st[j].dnumber;

                 st[j].name= name;
                 st[j].number= number;
                 st[j].dnumber = sdnumber;
             }
         }
     }

     qint16 low=1;
     qint16 hight=t-1;
     if((snumber>=st[low].number)&&(snumber<=st[hight].number))
     {
        while(low<=hight)
           {
              qint16 mid=(low+hight)/2;
              if(snumber==st[mid].number)
              {
                 QString a=st[mid].name;
                 QString b=st[mid].number;
                 QString c=st[mid].dnumber;
                 QString d=a+"             "+b+"             "+c;
                 ui->textBrowser->append(d);
                 break;
               }
              else if(snumber>st[mid].number) low=mid+1;
                else hight=mid-1;
            }
     }

}
