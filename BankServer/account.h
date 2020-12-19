#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
    private:
        long long accountId;
        double balance;
    public:
        Account(long accountId);
        double getBalance() const;
        long long getId() const;
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
        void setBalance(double balance) { this->balance = balance; }
};

#endif //ACCOUNT_H
