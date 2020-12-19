#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <time.h>
#include "account.h"
#include "counterparty.h"

class Transaction {
    private:
        long long transactionId;
        long long accountId;
        Counterparty counterparty;
        double amount;
        time_t timestamp;
    public:
        Transaction(long long transactionId, long long accountId,
            Counterparty counterparty, double amount, time_t timestamp);
        long long getTransactionId() const;
        long long getAccountId() const;
        double getAmount() const;
        Counterparty getCounterparty() const;
};

#endif //TRANSACTION_H
