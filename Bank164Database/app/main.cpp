#include "bank.h"
#include "cli.h"

int main() {
    Bank bank;
    Cli cli(bank);
    cli.start();
    return 0;
}
