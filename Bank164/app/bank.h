#ifndef BANK_H
#define BANK_H

#include "transaction.h"
#include <vector>
#include <unordered_map>
#include <memory>

class Bank {
private:
    unordered_map<long, unique_ptr<Account>> accounts;
public:
    Bank() { }
    bool createAccount(long accountId);
    bool accountExists(long accountId);
    double getBalance(long accountId);
    void performTransactions(vector<unique_ptr<Transaction>>& transactions);
    bool createCheckingAccount(long accountId);
    bool createSavingsAccount(long accountId);
    bool createSavingsAccount(long accountId, double minBalance);
};

#endif // BANK_H
