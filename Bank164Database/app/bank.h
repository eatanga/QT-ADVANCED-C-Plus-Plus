#ifndef BANK_H
#define BANK_H

#include <vector>
#include <unordered_map>
#include <map>
#include "transaction.h"
#include "database.h"

class Bank {
private:
    string name;
    long nextUniqueId = 1000;
    Database database;
public:
    void setName(string name) { this->name = name; }
    string getName() const { return name; }
    unique_ptr<Account> getAccount(long long accountId);
    void createAccount(long long accountId);
    bool accountExists(long long accountId);
    double getBalance(long long accountId);
    vector<unique_ptr<Account>> getAccounts();
    unique_ptr<Transaction> getTransaction(long long transactionId);
    vector<unique_ptr<Transaction>> getTransactions(long long accountId);
    void performTransactions(vector<unique_ptr<Transaction>>& transactions);
    long getUniqueId();
};

#endif // BANK_H
