#include <iostream>
#include "bank_account.h"

int BankAccount::deposit(int amount)
{
    if (amount > 0)
    {
        this->balance += amount;
    }
    return 0;
}

int BankAccount::withdraw(int amount) {

    if (amount >0 && amount <= balance)
    {
        balance -= amount;
    }
    return 0;
}
int BankAccount::bank_balance =0;

//friend function
void friend_display_balance(const BankAccount& account) {
    std::cout<<"Friend Display Balance: "<< account.balance<<"\n";
}

// static variable keeps value even when function are done running

// FREE FUNCTIONS
void display_balance(BankAccount account)
{
    std::cout<<"Display balance:"<<account.get_balance()<<"\n";

};

BankAccount get_account(int balance)
{
    BankAccount account(balance);

    return account;
};