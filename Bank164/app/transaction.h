#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <time.h>
#include "account.h"
#include "counterparty.h"

class Transaction {
    private:
        long transactionId;
        long accountId;
        Counterparty counterparty;
        double amount;
        time_t timestamp;

    public:
        Transaction(long transactionId, long accountId,
            Counterparty counterparty, double amount, time_t timestamp);
        double getAmount() const;
        long getAccountId() const;
        Counterparty getCounterparty() const;
        Transaction operator+(Transaction &t);
        void operator=(const Transaction &t);
        long getTransactionId();
        Account getAccount();
        time_t getTimestamp();
};


#endif //TRANSACTION_H
