#include "add.h"
#include "ui_add.h"
#include <QMessageBox>
#include <QDialog>
#include "mainwindow.h"

extern struct Student st[50000];

extern qint16 t;

Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
}

Add::~Add()
{
    delete ui;
}

void Add::on_pushButton_clicked()
{
    QString sname = ui->lineEdit->text();
    QString snumber = ui->lineEdit_2->text();
    QString sdnumber = ui->lineEdit_3->text();
    qint16 flag=0;
    for(int i=1;i<=t-1;i++)
    {
        if(snumber==st[i].number)
            flag=1;
    }
    if(flag==0)
    {
        st[t].name=sname;
        st[t].number=snumber;
        st[t].dnumber=sdnumber;
        t++;
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui-> lineEdit_3->clear();
    }
    else
    {
        QMessageBox::warning(NULL,"警告","学号重复");
        ui->lineEdit_2->clear();
    }

}

void Add::on_pushButton_2_clicked()
{
    this->close();
}
