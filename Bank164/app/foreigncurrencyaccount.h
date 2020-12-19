#ifndef FOREIGNCURRENCYACCOUNT_H
#define FOREIGNCURRENCYACCOUNT_H
#include "account.h"

class ForeignCurrencyAccount : public virtual Account
{
private:
   double conversionRate;
public:
    ForeignCurrencyAccount(long,double);
    double getForeignBalance();
};

#endif // FOREIGNCURRENCYACCOUNT_H
