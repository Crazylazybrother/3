#include "dinquire.h"
#include "ui_dinquire.h"
#include "mainwindow.h"

extern struct Student st[50000];

extern qint16 t;

DInquire::DInquire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DInquire)
{
    ui->setupUi(this);
}

DInquire::~DInquire()
{
    delete ui;
}

void DInquire::on_pushButton_clicked()
{
    QString dnumber = ui->lineEdit->text();
    ui->textBrowser->clear();

    QString name;
    QString number;
    QString sdnumber;

    QString b="姓名             学号             宿舍";
    ui->textBrowser->append(b);

    for (int i = 1; i<t; i++)
    {
        for (int j = i; j<t; j++)
        {
            if (st[i].dnumber>st[j].dnumber)
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
    if((dnumber>=st[low].dnumber)&&(dnumber<=st[hight].dnumber))
    {
       while(low<=hight)
          {
             qint16 mid=(low+hight)/2;
             if(dnumber==st[mid].dnumber)
             {
                QString a=st[mid].name;
                QString b=st[mid].number;
                QString c=st[mid].dnumber;
                QString d=a+"             "+b+"             "+c;
                ui->textBrowser->append(d);
                break;
              }
             else if(dnumber>st[mid].dnumber) low=mid+1;
               else hight=mid-1;
           }
    }

}
