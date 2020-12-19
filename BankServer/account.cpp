#include "account.h"

Account::Account(long accountId) {
    this->accountId = accountId;
    balance = 0.0;
}

double Account::getBalance() const {
    return balance;
}

long long Account::getId() const {
    return accountId;
}

void Account::setId(long accountId) {
    this->accountId = accountId;
}

double Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return amount;
    } else {
        return 0;
    }
}

double Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        return amount;
    } else {
        return 0;
    }
}
