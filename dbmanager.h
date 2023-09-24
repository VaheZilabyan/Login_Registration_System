#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>

class DBManager
{
public:
    DBManager();
    bool open();
    void close();
    QSqlDatabase db;
    QSqlQuery *query;
};

#endif // DBMANAGER_H
