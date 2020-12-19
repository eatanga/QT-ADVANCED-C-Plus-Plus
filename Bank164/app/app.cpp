#include "bank.h"
#include "account.h"
#include "counterparty.h"
#include "transaction.h"
#include "util.h"
#include "checkingaccount.h"
#include "savingsaccount.h"

// some accounts for testing purposes
const long ANNA_LEE_ACCOUNT_ID = 1234;
const long JAMES_BROWN_ACCOUNT_ID = 1235;
const Counterparty ACME_CO(5678, 1234, "Acme Co", "", "");
const Counterparty LEX_CORP(5678, 1235, "Lex Corp", "", "");
const Counterparty JOHN_SMITH(8877, 1122, "", "John", "Smith");

int main() {
    // create the bank
    Bank bank;

    // create the accounts in the bank
    bank.createCheckingAccount(ANNA_LEE_ACCOUNT_ID);
    bank.createCheckingAccount(JAMES_BROWN_ACCOUNT_ID);

    // create a vector of transactions
    vector<unique_ptr<Transaction>> testTransactions;
    testTransactions.push_back(make_unique<Transaction>
        (1001, ANNA_LEE_ACCOUNT_ID, LEX_CORP, 4000, 1555400000));
    testTransactions.push_back(make_unique<Transaction>
        (1002, JAMES_BROWN_ACCOUNT_ID, ACME_CO, 2000, 1555400000));
    testTransactions.push_back(make_unique<Transaction>
        (1003, ANNA_LEE_ACCOUNT_ID, ACME_CO, -2500, 1555500000));
    testTransactions.push_back(make_unique<Transaction>
        (1004, JAMES_BROWN_ACCOUNT_ID, JOHN_SMITH, -200, 1555500000));
    testTransactions.push_back(make_unique<Transaction>
        (1005, ANNA_LEE_ACCOUNT_ID, JOHN_SMITH, -200, 1555500000));
    testTransactions.push_back(make_unique<Transaction>
        (1006, ANNA_LEE_ACCOUNT_ID, LEX_CORP, 4000, 1555700000));

    // perform the transactions
    bank.performTransactions(testTransactions);

    // output the account balances
    cout << "Anna Lee's balance is " <<  bank.getBalance(ANNA_LEE_ACCOUNT_ID) << "\n";
    cout << "James Brown's balance is " << bank.getBalance(JAMES_BROWN_ACCOUNT_ID) << "\n";

    Counterparty lexCorp(0, 0, "MISC", "", ""),acmeCo(0, 0, "MISC", "", ""),johnSmith(0, 0, "MISC", "", "");

    Transaction t1(1001, ANNA_LEE_ACCOUNT_ID, lexCorp, 4000, 1555400000);

    Transaction t2(1003, ANNA_LEE_ACCOUNT_ID, acmeCo, -2500, 1555500000);

    Transaction t3(1005, ANNA_LEE_ACCOUNT_ID, johnSmith, -200, 1555500000);

    Transaction t4(1006, ANNA_LEE_ACCOUNT_ID, lexCorp, 4000, 1555700000);


    Transaction combined = t1 + t2 + t3 + t4;

    cout << combined.getTransactionId() << endl; // expected value is 0

    cout << combined.getAccount().getId() << endl; // expected value is 1234

    cout << combined.getAmount() << endl; // expected value is 5300

    cout << combined.getCounterparty().getBusinessName() << endl; // expected value is "MISC"

    cout << combined.getTimestamp() << endl; // expected value is 1555400000



    // testing the template function with account
    SavingsAccount acc(ANNA_LEE_ACCOUNT_ID);
    CheckingAccount chk(ANNA_LEE_ACCOUNT_ID);
    acc.deposit(300);
    chk.deposit(600);

    int maximum = max(acc.getBalance(),chk.getBalance());

    cout<<"The biggest account has $"<<maximum<<endl;


    int testmax= max(2000,3000);
      cout<< "testing the template "<< testmax<<endl;

    return 0;
}
