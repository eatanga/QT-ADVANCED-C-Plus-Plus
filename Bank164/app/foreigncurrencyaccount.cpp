#include "foreigncurrencyaccount.h"

ForeignCurrencyAccount::ForeignCurrencyAccount(long accountId, double conversionRate): Account(accountId),conversionRate(conversionRate)
{

}
double ForeignCurrencyAccount:: getForeignBalance(){
   return getBalance() * conversionRate;
}
