#ifndef DINQUIRE_H
#define DINQUIRE_H

#include <QDialog>

namespace Ui {
class DInquire;
}

class DInquire : public QDialog
{
    Q_OBJECT

public:
    explicit DInquire(QWidget *parent = 0);
    ~DInquire();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DInquire *ui;
};

#endif // DINQUIRE_H
