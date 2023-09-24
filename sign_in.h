#ifndef SIGN_IN_H
#define SIGN_IN_H

#include <dbmanager.h>
#include <QWidget>

namespace Ui {
class Sign_in;
}

class Sign_in : public QWidget
{
    Q_OBJECT

public:
    explicit Sign_in(QWidget *parent = nullptr);
    ~Sign_in();

private slots:
    void on_login_clicked();

    void on_back_from_sign_in_clicked();
    void on_pushButton_clicked();

signals:
    void signal_back();
    void signal_sign_up();
private:
    Ui::Sign_in *ui;
    DBManager dbm;
};

#endif // SIGN_IN_H
