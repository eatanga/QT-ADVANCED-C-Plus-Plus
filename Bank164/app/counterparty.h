#ifndef COUNTERPARTY_H
#define COUNTERPARTY_H

#include <iostream>
using namespace std;

class Counterparty {
private:
    long routingNumber;
    long accountId;
    string businessName;
    string firstName;
    string lastName;
public:
    Counterparty(long routingNumber, long accountId,
                 string businessName, string firstName, string lastName):
        routingNumber(routingNumber), accountId(accountId),
        businessName(businessName), firstName(firstName),
        lastName(lastName) {}
    long getRoutingNumber() const;
    long getAccountId() const;
    string getBusinessName() const;
    string getFirstName() const;
    string getLastName() const;
};

#endif //COUNTERPARTY_H
