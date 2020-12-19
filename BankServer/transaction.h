#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <time.h>
#include "account.h"
#include "counterparty.h"

class Account;

class Transaction {
private:
    long transactionId;
    Account& account;
    Counterparty& counterparty;
    double amount;
    time_t timestamp;
    friend class Database;
public:
    Transaction(long transactionId, Account& account,
    Counterparty& counterparty, double amount, time_t timestamp);
    long getId() const { return transactionId; }
    double getAmount() const { return amount; }
    Account& getAccount() const { return account; }
    Counterparty& getCounterparty() const { return counterparty; }
    void setTransactionId(long long id) { transactionId = id; }
    void setAmount(double amount) { this->amount = amount; }
    void setTimestamp(time_t time) { timestamp = time; }
};

#endif // TRANSACTION_H

