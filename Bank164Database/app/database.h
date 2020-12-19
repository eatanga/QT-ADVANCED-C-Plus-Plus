#ifndef DATABASE_H
#define DATABASE_H

#include <memory>
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
using namespace std;

class Database {
private:
    long getLatestRowId();
public:
    Database();
    void rebuildTestDatabase();
    void performTransaction(Transaction &transaction);
    void createAccount(long long accountId);
    bool accountExists(long long accountId);
    double getBalance(long long accountId);
    unique_ptr<Account> getAccount(long long accountId);
    vector<unique_ptr<Account>> getAccounts();
    unique_ptr<Transaction> getTransaction(long long transactionId);
    vector<unique_ptr<Transaction>> getTransactions(long long accountId);
};

#endif // DATABASE_H
