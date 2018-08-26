#ifndef NUINQUIRE_H
#define NUINQUIRE_H

#include <QDialog>

namespace Ui {
class NUInquire;
}

class NUInquire : public QDialog
{
    Q_OBJECT

public:
    explicit NUInquire(QWidget *parent = 0);
    ~NUInquire();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NUInquire *ui;

};

#endif // NUINQUIRE_H
