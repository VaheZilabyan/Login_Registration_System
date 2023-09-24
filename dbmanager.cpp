#include "dbmanager.h"
#include <QMessageBox>

DBManager::DBManager()
{
    /*query = new QSqlQuery(db);
    query->exec("CREATE TABLE User(Username TEXT, Password TEXT, Name TEXT, Surname TEXT, Mail TEXT, Phone TEXT)");

    QString n = "username";
    QString s = "password";
    query->prepare("insert into User (Username, Password) values ('"+n+"','"+s+"')");
    if (query->exec()) {
        QMessageBox::critical(0, "Save", "Saved");
    } else {
        QMessageBox::critical(0, "Error", "Error");
    }

    while (query->next()) {
        qDebug() << query->value(0).toString() << "+" << query->value(1).toString() << '\n';
    }*/
}

bool DBManager::open()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./data.db");
    if (db.open()) {
        qDebug() << "opened...\n";
        return true;
    }
    qDebug() << "does not opened\n";
    return false;
}

void DBManager::close()
{
    db.close();
}

