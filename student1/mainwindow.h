#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>
#include "add.h"
#include "modify.h"
#include "shan.h"
#include "ninquire.h"
#include "nuinquire.h"
#include "dinquire.h"

struct Student
{
    QString name;
    QString number;
    QString dnumber;
};


extern struct Student st[50000];
extern qint16 t;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void actions();
    void actions_2();
    void actions_3();
    void actions_4();
    void actions_5();
    void actions_6();
    void actions_7();
    void actions_8();
    void actions_9();
    void menu_4();
    void menu_5();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

    Add *add;
    Modify *modify;
    Shan *shan;
    NInquire *ninquire;
    NUInquire *nuinquire;
    DInquire *dinquire;


};

#endif // MAINWINDOW_H
