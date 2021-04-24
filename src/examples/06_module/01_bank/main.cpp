#include <iostream>
#include "bank_account.h"
using std::cout;
#include "atm.h"
using std::cin;

int main()
{
    //BankAccount account;
    char choice;
    ATM atm;

    do {


        atm.scan_card();
        atm.display_balance();
    cout << "Continue y?";
    cin >> choice;

    } while (choice == 'y' || choice == 'Y');


//        cout<< account.get_balance() <<"\n";
//        account.deposit(50);
//
//        cout<<account.get_balance()<<"\n";
//
//        account.withdraw(10);
//        cout<<account.get_balance();

	return 0;
}