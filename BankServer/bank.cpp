#include<iostream>
#include "bank.h"
#include "httpserver.h"
using namespace std;

Bank::~Bank() {
    for (auto pair : idAccountMap) {
        delete pair.second;
    }
}

long Bank::getUniqueId() {
    return nextUniqueId++;
}

int main() {
    Bank bank("1/64 Bank");
    HttpServer server;

    server.startServer(bank);

    return 0;
}
