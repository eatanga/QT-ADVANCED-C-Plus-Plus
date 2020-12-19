#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;

class Account {
    private:
        long long accountId;
        double balance;
    public:
        Account(long long accountId);
        double getBalance() const;
        long long getId() const;
        void setId(long long accountId);
        /**
         * Returns the amount withdrawn. If the requsted amount exceeds the total
         * balance nothing withdrawn and 0 is returned.
         */
        //double withdraw(double amount);
        virtual double withdraw(double amount);
        /**
         * Returns the amount deposited.
         */
        double deposit(double amount);
};

#endif //ACCOUNT_H
