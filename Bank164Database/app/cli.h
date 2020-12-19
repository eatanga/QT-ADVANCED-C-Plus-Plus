#ifndef CLI_H
#define CLI_H

#include <iostream>
#include "bank.h"

class Cli {
private:
    Bank &bank;
    void printGreeting();
    void printAccounts();
    void printTransactions(Account &accountId);
    void printTransaction(long transactionId);
    void mainMenu();
    void accountMenu(long accountId);
public:
    Cli(Bank &bank): bank(bank) {}
    void start();
};

#endif // CLI_H
