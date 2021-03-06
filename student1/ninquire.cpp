#include "ninquire.h"
#include "ui_ninquire.h"
#include "mainwindow.h"

extern struct Student st[50000];

extern qint16 t;

NInquire::NInquire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NInquire)
{
    ui->setupUi(this);
}

NInquire::~NInquire()
{
    delete ui;
}

void NInquire::on_pushButton_clicked()
{
    QString sname=ui->lineEdit->text();
    ui->textBrowser->clear();

    QString f="姓名             学号             宿舍";
    ui->textBrowser->append(f);

    QString name;
    QString number;
    QString sdnumber;

    for (int i = 1; i<t; i++)
    {
        for (int j = i; j<t; j++)
        {
            if (st[i].name>st[j].name)
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
    if((sname>=st[low].name)&&(sname<=st[hight].name))
    {
       while(low<=hight)
          {
             qint16 mid=(low+hight)/2;
             if(sname==st[mid].name)
             {
                QString a=st[mid].name;
                QString b=st[mid].number;
                QString c=st[mid].dnumber;
                QString d=c+"             "+b+"             "+a;
                ui->textBrowser->append(d);
                break;
              }
             else if(sname>st[mid].name) low=mid+1;
               else hight=mid-1;
           }
    }


}
