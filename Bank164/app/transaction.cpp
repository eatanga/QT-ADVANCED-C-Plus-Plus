#include "transaction.h"

Transaction::Transaction(long transactionId, long accountId, Counterparty counterparty,
        double amount, time_t timestamp): transactionId(transactionId),
        accountId(accountId), counterparty(counterparty), amount(amount),
        timestamp(timestamp) {
}


double Transaction::getAmount() const {
    return amount;
}

long Transaction::getAccountId() const {
    return accountId;
}

Counterparty Transaction::getCounterparty() const {
    return counterparty;
}

Transaction Transaction:: operator+(Transaction &t){
    Transaction newTransaction(transactionId=0,accountId,counterparty,amount + t.amount,timestamp);
    return newTransaction;
}

long Transaction :: getTransactionId(){
    return transactionId;
}

Account Transaction :: getAccount(){
    return accountId;
}

time_t Transaction :: getTimestamp(){
    return timestamp;
}

void Transaction :: operator=(const Transaction &t){
    if(t.accountId != accountId){
      throw "ERROR: cannot add transactions for different accounts.";
    }else
    {
        transactionId=0;
       Counterparty(0, 0, "MISC", "", "");
       amount+=t.amount;
       if (timestamp>t.timestamp){
           timestamp = t.timestamp;
       }

    }
}
