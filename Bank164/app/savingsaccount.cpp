#include "savingsaccount.h"



SavingsAccount::SavingsAccount(long accountId) : Account(accountId)
{

}

SavingsAccount::SavingsAccount(long accountId, double minimumBalance) : Account(accountId),minimumBalance(minimumBalance)
{

}

 double SavingsAccount :: withdraw(double amount){
    if ((getBalance()-amount) >= minimumBalance){
         Account :: withdraw(amount);
    return amount;
    }else{
        return 0;
    }
}


