#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QAction>
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QMessageBox>
#include <QDialog>

struct Student st[50000];

qint16 t=1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->action,SIGNAL(triggered()),this,SLOT(actions()));
    connect(ui->action_2,SIGNAL(triggered()),this,SLOT(actions_2()));
    connect(ui->action_3,SIGNAL(triggered()),this,SLOT(actions_3()));
    connect(ui->action_4,SIGNAL(triggered()),this,SLOT(actions_4()));
    connect(ui->action_5,SIGNAL(triggered()),this,SLOT(actions_5()));
    connect(ui->action_6,SIGNAL(triggered()),this,SLOT(actions_6()));
    connect(ui->action_7,SIGNAL(triggered()),this,SLOT(actions_7()));
    connect(ui->action_8,SIGNAL(triggered()),this,SLOT(actions_8()));
    connect(ui->action_9,SIGNAL(triggered()),this,SLOT(actions_9()));
    connect(ui->menu_4->menuAction(),SIGNAL(triggered()),this,SLOT(menu_4()));
    connect(ui->menu_5->menuAction(),SIGNAL(triggered()),this,SLOT(menu_5()));
    //connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFile file("student.dat");
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);
    QDataStream out(&file);
    for(int i=1;i<t;i++)
    {
      out<<st[i].name;
      out<<st[i].number;
      out<<st[i].dnumber;
    }
    file.close();

    this->close();
}

void MainWindow::actions()
{
    add = new Add(this);
    add->show();
}

void MainWindow::actions_2()
{
    modify = new Modify(this);
    modify->show();
}

void MainWindow::actions_3()
{
    shan =new Shan(this);
    shan->show();
}

void MainWindow::actions_4()
{
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
}

void MainWindow::actions_5()
{
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
}

void MainWindow::actions_6()
{
        QString name;
        QString number;
        QString sdnumber;

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
}

void MainWindow::actions_7()
{
    ninquire = new NInquire(this);
    ninquire->show();
}

void MainWindow::actions_8()
{
    nuinquire = new NUInquire(this);
    nuinquire->show();
}

void MainWindow::actions_9()
{
    dinquire = new DInquire(this);
    dinquire->show();
}

void MainWindow::menu_4()
{
    QFile file("student.dat");
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);
    QDataStream out(&file);
    for(int i=1;i<t;i++)
    {
      out<<st[i].name;
      out<<st[i].number;
      out<<st[i].dnumber;
    }
    file.close();
}

void MainWindow::menu_5()
{
    QFile file("student.dat");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(NULL,"提示","文件为空");
    }
    QDataStream in(&file);
    while(!in.atEnd())
    {
        in>>st[t].name>>st[t].number>>st[t].dnumber;
        t++;
    }
    file.close();
}




void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->clear();
    QString tile="姓名             学号             宿舍";
    ui->textBrowser->append(tile);
    for(int i=1;i<t;i++)
    {
        QString name=st[i].name;
        QString number=st[i].number;
        QString dnumber= st[i].dnumber;
        QString a=name+"             "+number+"             "+dnumber;
        ui->textBrowser->append(a);
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    QFile file("student.dat");
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);
    QDataStream out(&file);
    for(int i=1;i<t;i++)
    {
      out<<st[i].name;
      out<<st[i].number;
      out<<st[i].dnumber;
    }
    file.close();
}

void MainWindow::on_pushButton_4_clicked()
{
    QFile file("student.dat");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(NULL,"提示","文件为空");
    }
    QDataStream in(&file);
    while(!in.atEnd())
    {
        in>>st[t].name;
        in>>st[t].number;
        in>>st[t].dnumber;
        t++;
    }
    file.close();
}
