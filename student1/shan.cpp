#include "shan.h"
#include "ui_shan.h"
#include <QMessageBox>
#include <QDialog>
#include "mainwindow.h"

extern struct Student st[50000];

extern qint16 t;

Shan::Shan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Shan)
{
    ui->setupUi(this);
}

Shan::~Shan()
{
    delete ui;
}

void Shan::on_pushButton_clicked()
{
    qint16 flag=0;
    QString snumber = ui->lineEdit->text();
      for (int i = 1; i <= t; i++)
            if (st[i].number==snumber)
                flag = i;

      if(flag==0)
      {
         QMessageBox::warning(NULL,"警告","查无此人");
      }
      else{
      for (int i = flag; i<t; i++)
              {
                  int j = i + 1;
                  st[i].name=st[j].name;
                  st[i].number=st[j].number;
                  st[i].dnumber = st[j].dnumber;
              }
              t--;
      }
      ui->lineEdit->clear();
}
