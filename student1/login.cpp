#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDialog>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_2_clicked()
{
     QDialog::reject();
}

void Login::on_pushButton_clicked()
{
    QString stru=ui->lineEdit_2->text();
    QString strp=ui->lineEdit->text();

    if(stru==NULL)
         QMessageBox::warning(NULL,"警告","账号不能为空");
    else if(strp==NULL)
         QMessageBox::warning(NULL,"warning","密码不能为空");
    if(stru=="123456"&&strp=="123456")
    {
        QDialog::accept();
    }
     else
         QMessageBox::critical(NULL,"fail","登陆失败");
}
