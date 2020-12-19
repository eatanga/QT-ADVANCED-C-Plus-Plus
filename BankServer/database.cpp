#include "database.h"
#include "counterparty.h"
#include <time.h>
#include <QTime>

Database::Database() {
    DRIVER = QString("QSQLITE");
    if(!QSqlDatabase::isDriverAvailable(DRIVER)) {
        qWarning() << "ERROR: driver not available";
    }
}

void Database::open() {
    db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName("bank.sqlite");
    if(!db.open()) {
        qWarning() << "ERROR: " << db.lastError();
    }
}

void Database::close() {
    db.close();
    QSqlDatabase::removeDatabase(DRIVER);
}

void Database::getTransaction(long long transactionId, Transaction &transaction) {
    /**
     * TODO: Complete the following query so that the transaction for the
     * transactionId is loaded from the database and stored into the
     * passed-by-reference transaction. When it is working the CLI should do the
     * following:
     *
     * Account 1. Make a selection.
     * 1. Display balance.
     * 2. List all transactions.
     * 3. View transaction.
     * 4. Exit.
     * 3
     * Select transaction by id:
     * 2
     * Transaction 2 $-2122
     */
     QSqlQuery query;

     query.prepare("SELECT TransactionId, Amount, Timestamp FROM AccountTransaction WHERE TransactionId = :id");
    // Here is the query string: "SELECT TransactionId, Amount, Timestamp FROM AccountTransaction WHERE TransactionId = :id"
      query.addBindValue(transactionId);
      query.exec();
      query.next();
    transaction.setTransactionId(query.value(0).toLongLong());
    transaction.setAmount(query.value(1).toDouble());
    transaction.setTimestamp(query.value(2).toDouble());
}

void Database::getAccount(long long accountId, Account &account) {
    QSqlQuery query;
    query.prepare("SELECT AccountId, Balance FROM Account WHERE AccountId = ?");
    query.addBindValue(accountId);
    query.exec();
    query.next();
    account.setId(query.value(0).toLongLong());
    account.setBalance(query.value(1).toDouble());
}

unique_ptr<QSqlQuery> Database::getAccounts() {
    auto queryPtr = make_unique<QSqlQuery>();
    queryPtr->exec("SELECT AccountId, Balance FROM Account");
    return queryPtr;
}

unique_ptr<QSqlQuery> Database::getTransactions(Account &account) {
    auto selectPtr = make_unique<QSqlQuery>();
    selectPtr->prepare("SELECT TransactionId, CounterpartyId, Amount, Timestamp FROM AccountTransaction WHERE AccountId = ?");
    selectPtr->addBindValue(account.getId());
    return selectPtr;
}

void Database::performTransaction(Transaction &transaction) {
    Account& account = transaction.getAccount();
    if (transaction.getAmount() < 0) {
        account.withdraw(-transaction.getAmount());
    } else {
        account.deposit(transaction.getAmount());
    }
    QSqlQuery query;
    query.prepare("UPDATE Account SET Balance = ? WHERE AccountId = ?");
    query.addBindValue(account.getBalance());
    query.addBindValue(account.getId());
    query.exec();
}

long Database::getLatestRowId() {
    QSqlQuery query;
    query.exec("SELECT last_insert_rowid()");
    query.next();
    return query.value(0).toLongLong();
}

void Database::rebuildTestDatabase() {
    // drop sample table, if it exists
    QSqlQuery query;
    query.exec("DROP TABLE IF EXISTS AccountTransaction");
    query.exec("DROP TABLE IF EXISTS AccountTransaction");
    query.exec("DROP TABLE IF EXISTS AccountTransaction");
    query.exec("DROP TABLE IF EXISTS Counterparty");
    query.exec("DROP TABLE IF EXISTS Account");

    // (re)create table
    query.exec("CREATE TABLE Account (AccountId INTEGER PRIMARY KEY, Balance REAL)");
    query.exec("CREATE TABLE Counterparty (CounterpartyId INTEGER PRIMARY KEY, RoutingNumber INTEGER(8), AccountId INTEGER(8), BusinessName TEXT, FirstName TEXT, LastName TEXT, FOREIGN KEY(AccountId) REFERENCES Account(AccountId))");
    query.exec("CREATE TABLE AccountTransaction (TransactionId INTEGER PRIMARY KEY, AccountId, CounterpartyId, Amount REAL, Timestamp INTEGER(8), FOREIGN KEY(AccountId) REFERENCES Account(AccountId), FOREIGN KEY(CounterpartyId) REFERENCES Counterparty(CounterpartyId))");

    QSqlQuery insertAccount;
    insertAccount.prepare("INSERT INTO Account (Balance) VALUES (:balance)");
    insertAccount.bindValue(":balance", 5000);
    insertAccount.exec();
    long long accountId1 = getLatestRowId();
    insertAccount.bindValue(":balance", 9000);
    insertAccount.exec();
    long long accountId2 = getLatestRowId();

    QSqlQuery insertCounterParty1;
    insertCounterParty1.prepare("INSERT INTO CounterParty (RoutingNumber, AccountId, BusinessName, FirstName, LastName) VALUES (?, ?, ?, ?, ?)");
    insertCounterParty1.addBindValue(0);
    insertCounterParty1.addBindValue(1010);
    insertCounterParty1.addBindValue("Acme");
    insertCounterParty1.addBindValue("Wile");
    insertCounterParty1.addBindValue("Cyote");
    insertCounterParty1.exec();
    long long counterpartyId1 = getLatestRowId();

    QSqlQuery insertCounterParty2;
    insertCounterParty2.prepare("INSERT INTO CounterParty (RoutingNumber, AccountId, BusinessName, FirstName, LastName) VALUES (?, ?, ?, ?, ?)");
    insertCounterParty2.addBindValue(1111);
    insertCounterParty2.addBindValue(accountId2);
    insertCounterParty2.addBindValue("LexCorp");
    insertCounterParty2.addBindValue("Lex");
    insertCounterParty2.addBindValue("Luthor");
    insertCounterParty2.exec();
    long long counterpartyId2 = getLatestRowId();

    QSqlQuery insertTransaction;
    insertTransaction.prepare("INSERT INTO AccountTransaction (AccountId, CounterpartyId, Amount, Timestamp) VALUES (:accId, :counterId, :amount, :time)");
    insertTransaction.bindValue(":accId", accountId1);
    insertTransaction.bindValue(":countId", counterpartyId1);
    insertTransaction.bindValue(":amount", 4022);
    insertTransaction.bindValue(":time", 1570049000);
    insertTransaction.exec();
    insertTransaction.bindValue(":accId", accountId1);
    insertTransaction.bindValue(":amount", -2122);
    insertTransaction.exec();
    insertTransaction.bindValue(":accId", accountId1);
    insertTransaction.bindValue(":amount", 4102);
    insertTransaction.exec();
    insertTransaction.bindValue(":accId", accountId1);
    insertTransaction.bindValue(":amount", -1002);
    insertTransaction.exec();
    insertTransaction.bindValue(":accId", accountId2);
    insertTransaction.bindValue(":countId", counterpartyId2);
    insertTransaction.bindValue(":amount", 8000);
    insertTransaction.exec();
    insertTransaction.bindValue(":accId", accountId2);
    insertTransaction.bindValue(":amount", -4000);
    insertTransaction.exec();
}
