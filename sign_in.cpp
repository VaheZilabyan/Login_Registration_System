#include "sign_in.h"
#include "ui_sign_in.h"

#include <QMessageBox>
#include <QFile>

Sign_in::Sign_in(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sign_in)
{
    ui->setupUi(this);
}

Sign_in::~Sign_in()
{
    delete ui;
}

void Sign_in::on_login_clicked()
{
    if (dbm.open()) {
        dbm.query = new QSqlQuery(dbm.db);
        dbm.query->exec("CREATE TABLE User(Username TEXT, Password TEXT, Name TEXT, Surname TEXT, Mail TEXT, Phone TEXT)");

        if(dbm.query->exec("select * from User where Username='"+ui->lineEdit_login->text()+"' and Password='"+ui->lineEdit_password->text()+"'")) {
            // counti 1-i depqum e petq mutq gorcel
            int count = 0;
            QString name = "";
            QString surname = "";
            while (dbm.query->next()) {
                ++count;
                name = dbm.query->value(2).toString();
                surname = dbm.query->value(3).toString();
            }
            if (count == 1) {
                qDebug() << "USER FINDED" << '\n';
                QMessageBox::information(0, "You Log in", "You login successfully, " + name + " " + surname);
            } else {
                QMessageBox::information(0, "Error", "Wrong login or password...");
            }
        }
        dbm.close();
    } else {
        qDebug() << "error when open...\n";
    }
}


void Sign_in::on_back_from_sign_in_clicked()
{
    emit signal_back();
}


void Sign_in::on_pushButton_clicked()
{
    emit signal_sign_up();
}

