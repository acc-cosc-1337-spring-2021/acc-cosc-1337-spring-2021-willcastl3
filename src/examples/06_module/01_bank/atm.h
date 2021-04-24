//atm.h
#ifndef ATM_H
#define ATM_H
#include "bank_account.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

class ATM{

public:
    ATM();
    void display_balance()const;
    void scan_card();
private:
    std::vector<BankAccount>accounts;
    int get_balance_from_DB();
    int customer_index{0};

};

