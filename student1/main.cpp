#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QDebug>
#include<windows.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login login;
     MainWindow w;
    if(login.exec()==QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else
    return 0;
}
