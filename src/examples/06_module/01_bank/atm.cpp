//atm.cpp

#include "atm.h"
using std::cout;

ATM::ATM()
{
    accounts.push_back(BankAccount(get_balance_from_DB()));
    accounts.push_back(BankAccount(get_balance_from_DB()));
    accounts.push_back(BankAccount(get_balance_from_DB()));
    accounts.push_back(BankAccount(get_balance_from_DB()));
    accounts.push_back(BankAccount(get_balance_from_DB()));

}

void ATM::scan_card() {

    customer_index = rand() % accounts.size() -1 +1;
}
void ATM::display_balance() const {
    BankAccount account = accounts[customer_index];
    cout<<"ATM balance: "<< account.get_balance()<<"\n";
}

int ATM::get_balance_from_DB() {

    return rand() % 10000 + 1;
}

