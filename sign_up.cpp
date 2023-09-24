#include "sign_up.h"
#include "ui_sign_up.h"
#include "checker.h"

#include <QMessageBox>
#include <Qfile>

Sign_up::Sign_up(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sign_up)
{
    ui->setupUi(this);
}

Sign_up::~Sign_up()
{
    delete ui;
}

void Sign_up::on_back_from_sign_up_clicked()
{
    emit signal_back();
}


void Sign_up::on_Create_clicked()
{
    // stugel, ete meky datark a chgrancel, check funkcia grel vor true kveradarcni erb bolory dashtery jisht en lracvac
    // loginy chi kara krknvi
    bool fields_is_correct = Checker::fields_is_correct(ui).first;
    QString errors = Checker::fields_is_correct(ui).second;

    if (fields_is_correct){
        if(dbm.open()) {
            dbm.query = new QSqlQuery(dbm.db);
            dbm.query->exec("CREATE TABLE User(Username TEXT, Password TEXT, Name TEXT, Surname TEXT, Mail TEXT, Phone TEXT)");
            dbm.query->prepare("insert into User (Username, Password, Name, Surname, Mail, Phone) values ('"+ui->create_login->text()+"','"+ui->create_password->text()+"','"+ui->name->text()+"','"+ui->surname->text()+"','"+ui->mail->text()+"','"+ui->phone->text()+"')");
            if (dbm.query->exec()) {
                QMessageBox::information(this, "Account Created", "Now yo can log in " + ui->name->text() + " " + ui->surname->text());
            } else {
                QMessageBox::critical(this, tr("Error"), tr("Account not created!!!"));
            }

            while (dbm.query->next()) {
                qDebug() << dbm.query->value(0).toString() << "+" << dbm.query->value(1).toString() << '\n';
            }
            dbm.close();
        } else {
            qDebug() << "error when open...\n";
        }

        ui->name->clear();
        ui->surname->clear();
        ui->phone->clear();
        ui->mail->clear();
        ui->create_login->clear();
        ui->create_password->clear();
        emit signal_back();
    } else {
        QMessageBox::information(this, "Wrong fields", errors);
    }
}

