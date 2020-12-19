#include "cli.h"
#include "transaction.h"

void Cli::printAccounts() {
    /**
     * TODO: Display all accounts. An SQL select query is provided below.
     * When it is working the CLI should do the following:
     *
     * 1. List all accounts.
     * 2. View account.
     * 3. Exit.
     * 1
     *
     * Bank Accounts
     * Account 1 has balance 5000
     * Account 2 has balance 9000
     */

    cout << "Bank Accounts" << endl;
    // Here is the query string: "SELECT AccountId, Balance FROM Account"
}

void Cli::printTransactions(Account &account) {
    /**
     * TODO: Display all transactions. An SQL select query is provided below.
     * When it is working the CLI should do the following:
     *
     * Account 1. Make a selection.
     * 1. Display balance.
     * 2. List all transactions.
     * 3. View transaction.
     * 4. Exit.
     * 2
     *
     * Transactions for account 1
     * Transaction 1. 1 4022
     * Transaction 2. 2 -2122
     * Transaction 3. 3 4102
     * Transaction 4. 4 -1002
     */

    cout << endl << "Transactions for account " << account.getId() << endl;
    // Here is the query: "SELECT TransactionId, CounterpartyId, Amount, Timestamp FROM AccountTransaction WHERE AccountId = :id"
}

void Cli::printTransaction(long transactionId) {
    Account account(0);
    Counterparty counterparty(0, 0, 0, "", "", "");
    Transaction transaction(0, account, counterparty, 0, 0);
    bank.getDatabase().getTransaction(transactionId, transaction);
    cout << "Transaction " << transaction.getId() << " $" << transaction.getAmount() << endl;
}

void Cli::printGreeting() {
    cout << "============================" << endl;
    cout << "=  Welcome to " << bank.getName() << ".   =" << endl;
    cout << "============================" << endl;
}

void Cli::accountMenu(long accountId) {
    int selection;
    bool exit = false;

    Account account(0);
    bank.getDatabase().getAccount(accountId, account);

    while (!exit) {
        cout << endl;
        cout << "Account " << account.getId() << ". Make a selection." << endl;
        cout << "1. Display balance. " << endl;
        cout << "2. List all transactions. " << endl;
        cout << "3. View transaction. " << endl;
        cout << "4. Exit. " << endl;
        cin >> selection;
        switch (selection) {
            case 1:
                cout << endl << "Current balance is $" << account.getBalance() << endl;
                break;
            case 2:
                printTransactions(account);
                break;
            case 3:
                int transactionId;
                cout << "Select transaction by id: " << endl;
                cin >> transactionId;
                printTransaction(transactionId);
                break;
            case 4:
                exit = true;
                break;
            default:
                cout << "Invlaid selection." << endl;
        }
    }
}

void Cli::mainMenu() {
    int selection;
    long accountId;
    bool exit = false;

    while (!exit) {
        cout << endl;
        printGreeting();
        cout << "1. List all accounts. " << endl;
        cout << "2. View account. " << endl;
        cout << "3. Exit. " << endl;
        cin >> selection;
        switch (selection) {
            case 1:
                printAccounts();
                break;
            case 2:
                cout << "Select account: ";
                cin >> accountId;
                accountMenu(accountId);
                cout << endl;
                break;
            case 3:
                cout << "Goodbye." << endl;
                exit = true;
                break;
            default:
                cout << "Invlaid selection." << endl;
        }
    }
}

void Cli::start() {
    mainMenu();
}
