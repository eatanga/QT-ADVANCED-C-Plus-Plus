#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <vector>
#include "account.h"
#include "transaction.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <memory>
using namespace std;

class Database {
private:
    QSqlDatabase db;
    long getLatestRowId();
    QString DRIVER;
public:
    Database();
    void open();
    void rebuildTestDatabase();
    void close();
    void performTransaction(Transaction &transaction);
    void getAccount(long long accountId, Account &account);
    unique_ptr<QSqlQuery> getAccounts();
    void getTransaction(long long transactionId, Transaction &transaction);
    unique_ptr<QSqlQuery> getTransactions(Account &account);
};

#endif // DATABASE_H
