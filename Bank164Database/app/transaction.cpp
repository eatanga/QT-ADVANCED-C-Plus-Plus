#include "transaction.h"

Transaction::Transaction(long long transactionId, long long accountId, Counterparty counterparty,
        double amount, time_t timestamp): transactionId(transactionId),
        accountId(accountId), counterparty(counterparty), amount(amount),
        timestamp(timestamp) {
}

long long Transaction::getTransactionId() const {
    return transactionId;
}

long long Transaction::getAccountId() const {
    return accountId;
}

double Transaction::getAmount() const {
    return amount;
}

Counterparty Transaction::getCounterparty() const {
    return counterparty;
}
