#include "sign_up.h"
#include "checker.h"

#include <QMessageBox>
#include <QLabel>
#include <Qfile>

Sign_up::Sign_up(QWidget *parent) :
    QWidget(parent)
{
    create_button = new QPushButton("Create Account");
    back_button = new QPushButton("Back");
    name = new QLineEdit(this);
    surname = new QLineEdit(this);
    phone = new QLineEdit(this);
    mail = new QLineEdit(this);
    login = new QLineEdit(this);
    password = new QLineEdit(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *label_sign_up = new QLabel("Sign up");
    QFont font = label_sign_up->font();
    font.setBold(true);
    font.setPointSize(16);
    label_sign_up->setFont(font);
    label_sign_up->setAlignment(Qt::AlignCenter);

    // grid_layout
    QGridLayout *grid_layout = new QGridLayout();
    QLabel *label_name = new QLabel("Name");
    QLabel *label_surname = new QLabel("Surname");
    QLabel *label_phone = new QLabel("Phone");
    QLabel *label_mail = new QLabel("Mail");
    QLabel *label_login = new QLabel("Login");
    QLabel *label_password = new QLabel("Password");
    label_name->setAlignment(Qt::AlignLeft);
    label_surname->setAlignment(Qt::AlignLeft);
    label_phone->setAlignment(Qt::AlignLeft);
    label_mail->setAlignment(Qt::AlignLeft);
    label_login->setAlignment(Qt::AlignLeft);
    label_password->setAlignment(Qt::AlignLeft);

    grid_layout->addWidget(label_name, 0, 0);
    grid_layout->addWidget(name, 0, 1);
    grid_layout->addWidget(label_surname, 1, 0);
    grid_layout->addWidget(surname, 1, 1);
    grid_layout->addWidget(label_phone, 2, 0);
    grid_layout->addWidget(phone, 2, 1);
    grid_layout->addWidget(label_mail, 3, 0);
    grid_layout->addWidget(mail, 3, 1);
    grid_layout->addWidget(label_login, 4, 0);
    grid_layout->addWidget(login, 4, 1);
    grid_layout->addWidget(label_password, 5, 0);
    grid_layout->addWidget(password, 5, 1);

    // create account layout
    QHBoxLayout *hor_layout = new QHBoxLayout();
    hor_layout->addWidget(back_button);
    hor_layout->addWidget(create_button);

    mainLayout->addWidget(label_sign_up);
    mainLayout->addLayout(grid_layout);
    mainLayout->addLayout(hor_layout);

    //signals and slots
    connect(back_button, &QPushButton::clicked, this, &Sign_up::on_back_from_sign_up_clicked);
    connect(create_button, &QPushButton::clicked, this, &Sign_up::on_Create_clicked);
}

Sign_up::~Sign_up()
{
}

void Sign_up::on_back_from_sign_up_clicked()
{
    emit signal_back();
}


void Sign_up::on_Create_clicked()
{
    // stugel, loginy chi kara krknvi

    QVector<QLineEdit*> data;
    data.push_back(name);
    data.push_back(surname);
    data.push_back(phone);
    data.push_back(mail);
    data.push_back(login);
    data.push_back(password);

    QPair<bool, QString> result = Checker::fields_is_correct(std::move(data));
    bool fields_is_correct = result.first;
    QString errors = result.second;

    if (fields_is_correct){
        if(dbm.open()) {
            dbm.query = new QSqlQuery(dbm.db);
            dbm.query->prepare("insert into User (Username, Password, Name, Surname, Mail, Phone) values ('"+login->text()+"','"+password->text()+"','"+name->text()+"','"+surname->text()+"','"+mail->text()+"','"+phone->text()+"')");
            if (dbm.query->exec()) {
                QMessageBox::information(this, "Account Created", "Now yo can log in " + name->text() + " " + surname->text());
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

        name->clear();
        surname->clear();
        phone->clear();
        mail->clear();
        login->clear();
        password->clear();

        //back to main menu
        emit signal_back();
    } else {
        QMessageBox::information(this, "Wrong fields", errors);
    }
}

