#ifndef BANK_H
#define BANK_H

#include <string>
#include <map>
#include "account.h"
#include "database.h"
using namespace std;

class Bank {
private:
    string name;
    map<long, Account*> idAccountMap;
    long nextUniqueId = 1000;
    Database database;
public:
    Bank(string name) : name(name), database() {
        database.open();
        database.rebuildTestDatabase();
        database.close();
    }
    ~Bank();
    void setName(string name) { this->name = name; }
    string getName() const { return name; }
    Database& getDatabase() { return database; }
    long getUniqueId();
};

#endif
