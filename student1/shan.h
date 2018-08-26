#ifndef SHAN_H
#define SHAN_H

#include <QDialog>

namespace Ui {
class Shan;
}

class Shan : public QDialog
{
    Q_OBJECT

public:
    explicit Shan(QWidget *parent = 0);
    ~Shan();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Shan *ui;
};

#endif // SHAN_H
