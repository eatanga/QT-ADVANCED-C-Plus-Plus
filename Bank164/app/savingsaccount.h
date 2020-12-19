#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "account.h"

class SavingsAccount : public Account
{
private:
    double minimumBalance;
public:
    SavingsAccount(long accountId);
    SavingsAccount(long accountId,double minimumBalance);
    double withdraw(double amount);
};

#endif // SAVINGSACCOUNT_H
