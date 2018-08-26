#ifndef NINQUIRE_H
#define NINQUIRE_H

#include <QDialog>

namespace Ui {
class NInquire;
}

class NInquire : public QDialog
{
    Q_OBJECT

public:
    explicit NInquire(QWidget *parent = 0);
    ~NInquire();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NInquire *ui;
};

#endif // NINQUIRE_H
