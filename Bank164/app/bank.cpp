#include "bank.h"
#include "checkingaccount.h"
#include "savingsaccount.h"

bool Bank::createAccount(long accountId) {
    bool success = false;
    if (accounts.find(accountId) == accounts.end()) {
        accounts[accountId] = make_unique<Account>(accountId);
        success = true;
    }
    return success;
}

bool Bank::accountExists(long accountId) {
    return accounts.find(accountId) != accounts.end();
}

double Bank::getBalance(long accountId) {
    double balance = 0;
    if (accounts.find(accountId) != accounts.end()) {
        balance = accounts[accountId]->getBalance();
    }
    return balance;
}

void Bank::performTransactions(vector<unique_ptr<Transaction>>& transactions) {
    for (auto &transaction: transactions) {
        double amount = transaction->getAmount();
        long accountId = transaction->getAccountId();
        if (accounts.find(accountId) == accounts.end()) {
            continue; // skip transaction if account not found
        }
        if (amount >= 0) {
            accounts[accountId]->deposit(amount);
        } else {
            accounts[accountId]->withdraw(-amount);
        }
    }
}
bool Bank :: createCheckingAccount(long accountId){
    bool success = false;

        if (accounts.find(accountId) == accounts.end()) {

            accounts.emplace(accountId, make_unique<CheckingAccount>(accountId));

            success = true;

        }

        return success;
}
bool  Bank :: createSavingsAccount(long accountId){
    bool success = false;
    if (accounts.find(accountId) == accounts.end()) {

        accounts.emplace(accountId, make_unique<SavingsAccount>(accountId));

        success = true;

    }

    return success;
}
bool  Bank :: createSavingsAccount(long accountId, double minBalance){
    bool success = false;
    if (accounts.find(accountId) == accounts.end()) {

        accounts.emplace(accountId, make_unique<SavingsAccount>(accountId, minBalance));

        success = true;

    }

    return success;
}

