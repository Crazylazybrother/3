#include "modify.h"
#include "ui_modify.h"
#include <QMessageBox>
#include <QDialog>
#include "mainwindow.h"

extern struct Student st[50000];

extern qint16 t;

Modify::Modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modify)
{
    ui->setupUi(this);
}

Modify::~Modify()
{
    delete ui;
}

void Modify::on_pushButton_clicked()
{
     qint16 flaf=0;
     QString number = ui->lineEdit->text();
     for(int i=1;i<t;i++)
     {
         if(st[i].number==number)
             flaf=i;
     }

     QString sname = ui->lineEdit_2->text();
     QString snumber = ui->lineEdit_3->text();
     QString sdnumber = ui->lineEdit_4->text();

     qint16 flag=0;
     for(int i=1;i<=t-1;i++)
     {
         if(snumber==st[i].number)
             flag=1;
     }
     if(flag==0)
     {
         st[flaf].name=sname;
         st[flaf].number=snumber;
         st[flaf].dnumber=sdnumber;

         ui->lineEdit->clear();
         ui->lineEdit_2->clear();
         ui->lineEdit_3->clear();
         ui->lineEdit_4->clear();
     }
     else
     {
         QMessageBox::warning(NULL,"警告","学号重复");
         ui->lineEdit_3->clear();
     }
}

void Modify::on_pushButton_2_clicked()
{
    this->close();
}
