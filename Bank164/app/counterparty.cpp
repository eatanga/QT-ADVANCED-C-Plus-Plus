#include "counterparty.h"

long Counterparty::getRoutingNumber() const {
    return routingNumber;
}

long Counterparty::getAccountId() const {
    return accountId;
}

string Counterparty::getBusinessName() const {
    return businessName;
}

string Counterparty::getFirstName() const {
    return firstName;
}

string Counterparty::getLastName() const {
    return lastName;
}
