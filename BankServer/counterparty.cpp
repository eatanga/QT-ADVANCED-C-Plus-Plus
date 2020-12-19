#include "counterparty.h"

Counterparty::Counterparty(long counterPartyId, long routingNumber, long accountNumber, std::string businessName, string firstName, std::string lastName) {
    this->counterPartyId = counterPartyId;
    this->routingNumber = routingNumber;
    this->accountId = accountNumber;
    this->businessName = businessName;
    this->firstName = firstName;
    this->lastName = lastName;
}
