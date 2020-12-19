#include <QtTest>
#include "bank.h"

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
    void test_getAccount();
};

TestBank::TestBank() {
}

TestBank::~TestBank() {
}

void TestBank::test_createAccount() {
    Bank bank;

    bank.createAccount(ANNA_LEE_ACCOUNT_ID);
    bank.createAccount(JAMES_BROWN_ACCOUNT_ID);

    QVERIFY(bank.accountExists(ANNA_LEE_ACCOUNT_ID));
    QVERIFY(bank.accountExists(JAMES_BROWN_ACCOUNT_ID));
    QVERIFY(!bank.accountExists(1337));
}

void TestBank::test_performEmptyTransactions() {
    Bank bank;
    bank.createAccount(ANNA_LEE_ACCOUNT_ID);
    bank.createAccount(JAMES_BROWN_ACCOUNT_ID);
    vector<unique_ptr<Transaction>> testTransactions;

    bank.performTransactions(testTransactions);

    QCOMPARE(bank.getBalance(ANNA_LEE_ACCOUNT_ID), 0);
    QCOMPARE(bank.getBalance(JAMES_BROWN_ACCOUNT_ID), 0);
}

void TestBank::test_performTransactions() {
    Bank bank;
    bank.createAccount(ANNA_LEE_ACCOUNT_ID);
    bank.createAccount(JAMES_BROWN_ACCOUNT_ID);
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

void TestBank::test_getAccount() {
    Bank bank;
    bank.createAccount(ANNA_LEE_ACCOUNT_ID);
    bank.createAccount(JAMES_BROWN_ACCOUNT_ID);

    unique_ptr<Account> accountAnna = bank.getAccount(ANNA_LEE_ACCOUNT_ID);
    unique_ptr<Account> accountJames = bank.getAccount(JAMES_BROWN_ACCOUNT_ID);

    QCOMPARE(accountAnna->getId(), ANNA_LEE_ACCOUNT_ID);
    QCOMPARE(accountJames->getId(), JAMES_BROWN_ACCOUNT_ID);
}

QTEST_APPLESS_MAIN(TestBank)

#include "tst_testbank.moc"
