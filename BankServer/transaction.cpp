#include "transaction.h"

Transaction::Transaction(long transactionId, Account& account, Counterparty& counterparty, double amount, time_t timestamp) : account(account), counterparty(counterparty) {
    this->transactionId = transactionId;
    this->amount = amount;
    this->timestamp = timestamp;
}
