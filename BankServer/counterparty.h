#ifndef COUNTERPARTY_H
#define COUNTERPARTY_H

#include <iostream>
using namespace std;

class Counterparty {
    private:
        long counterPartyId;
        long routingNumber;
        long accountId;
        string businessName;
        string firstName;
        string lastName;
        friend class Database;
    public:
        Counterparty(long conterPartyId, long routingNumber, long accountId,
        string businessName, string firstName, string LastName);
        long long getCounterPartyId() const { return counterPartyId; }
        long getRoutingNumber() const { return routingNumber; }
        long getAccountId() const { return accountId; }
        string getBusinessName() const {return businessName; }
        string getFirstName() const { return firstName; }
        string getLastName() const { return lastName; }
        void setCounterPartyId(long id) { counterPartyId = id; }
        void setRoutingNumber(long routingNumber) { this->routingNumber = routingNumber; }
        void setAccountId(long accountId) { this->accountId = accountId; }
        void setBusinessName(string businessName) { this->businessName = businessName; }
        void setFirstName(string firstName) { this->firstName = firstName; }
        void setLastName(string lastName) { this->lastName = lastName; }
    };

#endif //COUNTERPARTY_H
