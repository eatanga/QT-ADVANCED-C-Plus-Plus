#include <QtTest>
#include "bank.h"
#include "checkingaccount.h"
#include "savingsaccount.h"

// some accounts for testing purposes
const long ANNA_LEE_ACCOUNT_ID = 1234;
const long JAMES_BROWN_ACCOUNT_ID = 1235;
const Counterparty ACME_CO(5678, 1234, "Acme Co", "", "");
const Counterparty LEX_CORP(5678, 1235, "Lex Corp", "", "");
const Counterparty JOHN_SMITH(8877, 1122, "", "John", "Smith");

class TestBank : public QObject {
    Q_OBJECT
public:
    TestBank();
    ~TestBank();
private slots:
    void test_createAccount();
    void test_performEmptyTransactions();
    void test_performTransactions();
    void test_checkingDeposit();
    void test_checkingWithdraw();
    void test_savingsDeposit();
    void test_savingsWithdraw();
    void test_performSavingsCheckingTransactions();
};

TestBank::TestBank() {
}

TestBank::~TestBank() {
}

void TestBank::test_createAccount() {
    Bank bank;

    bank.createCheckingAccount(ANNA_LEE_ACCOUNT_ID);
    bank.createSavingsAccount(JAMES_BROWN_ACCOUNT_ID);

    QVERIFY(bank.accountExists(ANNA_LEE_ACCOUNT_ID));
    QVERIFY(bank.accountExists(JAMES_BROWN_ACCOUNT_ID));
    QVERIFY(!bank.accountExists(1337));
}

void TestBank::test_performEmptyTransactions() {
    Bank bank;
    bank.createCheckingAccount(ANNA_LEE_ACCOUNT_ID);
    bank.createSavingsAccount(JAMES_BROWN_ACCOUNT_ID);
    vector<unique_ptr<Transaction>> testTransactions;

    bank.performTransactions(testTransactions);

    QCOMPARE(bank.getBalance(ANNA_LEE_ACCOUNT_ID), 0);
    QCOMPARE(bank.getBalance(JAMES_BROWN_ACCOUNT_ID), 0);
}

void TestBank::test_performTransactions() {
    Bank bank;
    bank.createCheckingAccount(ANNA_LEE_ACCOUNT_ID);
    bank.createSavingsAccount(JAMES_BROWN_ACCOUNT_ID);
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

    bank.performTransactions(testTransactions);

    QCOMPARE(bank.getBalance(ANNA_LEE_ACCOUNT_ID), 5300);
    QCOMPARE(bank.getBalance(JAMES_BROWN_ACCOUNT_ID), 1800);
}

void TestBank:: test_checkingDeposit()
{
    CheckingAccount ch(ANNA_LEE_ACCOUNT_ID);
    CheckingAccount gh(JAMES_BROWN_ACCOUNT_ID);

    ch.deposit(500);
    gh.deposit(-500);

    QCOMPARE(ch.getBalance(),500);
    QCOMPARE(gh.getBalance(),0);

}

void TestBank:: test_checkingWithdraw()
{
    CheckingAccount ch(ANNA_LEE_ACCOUNT_ID);
    CheckingAccount gh(JAMES_BROWN_ACCOUNT_ID);
    ch.deposit(800);
    ch.withdraw(500);
    gh.withdraw(200);

    QCOMPARE(ch.getBalance(),300);
    QCOMPARE(gh.getBalance(),0);

}

void TestBank:: test_savingsDeposit()
{
    SavingsAccount s(ANNA_LEE_ACCOUNT_ID, 25);
    SavingsAccount sa(JAMES_BROWN_ACCOUNT_ID, 50);
    s.deposit(800);
    sa.deposit(-200);

    QCOMPARE(s.getBalance(),800);
    QCOMPARE(sa.getBalance(),0);

}

void TestBank:: test_savingsWithdraw()
{
    SavingsAccount s(ANNA_LEE_ACCOUNT_ID, 25);
    SavingsAccount sa(JAMES_BROWN_ACCOUNT_ID, 50);
    s.deposit(800);
    s.withdraw(400);
    sa.deposit(1200);
    sa.withdraw(1175);


    QCOMPARE(s.getBalance(),400);
    QCOMPARE(sa.getBalance(),1200);
}

void TestBank :: test_performSavingsCheckingTransactions()
{
    Bank bank;
    bank.createSavingsAccount(ANNA_LEE_ACCOUNT_ID, 100);
    bank.createCheckingAccount(JAMES_BROWN_ACCOUNT_ID);

    vector<unique_ptr<Transaction>> testTransactions;
    testTransactions.push_back(make_unique<Transaction>
        (1001, ANNA_LEE_ACCOUNT_ID, LEX_CORP, 1000, 1555400000));
    testTransactions.push_back(make_unique<Transaction>
        (1002, JAMES_BROWN_ACCOUNT_ID, ACME_CO, 1000, 1555400000));
    testTransactions.push_back(make_unique<Transaction>
        (1003, ANNA_LEE_ACCOUNT_ID, ACME_CO, -950, 1555500000));
    testTransactions.push_back(make_unique<Transaction>
        (1004, JAMES_BROWN_ACCOUNT_ID, JOHN_SMITH, -950, 1555500000));

    bank.performTransactions(testTransactions);

    QCOMPARE(bank.getBalance(ANNA_LEE_ACCOUNT_ID),1000);
    QCOMPARE(bank.getBalance(JAMES_BROWN_ACCOUNT_ID), 50);
};

QTEST_APPLESS_MAIN(TestBank)

#include "tst_testbank.moc"
