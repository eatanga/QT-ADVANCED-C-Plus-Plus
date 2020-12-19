#include<iostream>
#include "bank.h"
#include "cli.h"
using namespace std;

void Bank::performTransactions(vector<unique_ptr<Transaction>>& transactions) {
    for (auto &transaction: transactions) {
        double amount = transaction->getAmount();
        long accountId = transaction->getAccountId();
        auto account = database.getAccount(accountId);
        if (account == nullptr) {
            continue; // skip transaction if account not found
        }
        if (amount >= 0) {
            account->deposit(amount);
        } else {
            account->withdraw(-amount);
        }
    }
}

void Bank::createAccount(long long accountId) {
    database.createAccount(accountId);
}

bool Bank::accountExists(long long accountId) {
    return database.accountExists(accountId);
}

double Bank::getBalance(long long accountId) {
    return database.getBalance(accountId);
}

unique_ptr<Account> Bank::getAccount(long long accountId) {
    return database.getAccount(accountId);
}

vector<unique_ptr<Account>> Bank::getAccounts() {
    return database.getAccounts();
}

unique_ptr<Transaction> Bank::getTransaction(long long transactionId) {
    return database.getTransaction(transactionId);
}

vector<unique_ptr<Transaction>> Bank::getTransactions(long long accountId) {
    return database.getTransactions(accountId);
}

long Bank::getUniqueId() {
    return nextUniqueId++;
}
