#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "util.h"

class Account  {
    private:
        long accountId;
        double balance;
    public:
        Account(long accountId);

        double getBalance() const;
        long getId() const;
        void setId(long accountId);

        /**
         * Returns the amount withdrawn. If the requsted amount exceeds the total
         * balance nothing withdrawn and 0 is returned.
         */
        double withdraw(double amount);
        /**
         * Returns the amount deposited.
         */
        double deposit(double amount);
};

#endif //ACCOUNT_H
