#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "bank_account.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Test Configuration, verification")
{
    BankAccount account;
    REQUIRE(account.get_balance()== 0);

}
TEST_CASE("Test bank account deposit with invalid amount")
{
    BankAccount account;
    REQUIRE(account.get_balance()==0);

    account.deposit(50);
    REQUIRE(account.get_balance()==50);

    account.deposit(-10);
    REQUIRE(account.get_balance()==50);
}

TEST_CASE("Test bank account withdraw with valid amount")
{
    BankAccount account;
    REQUIRE(account.get_balance()==0);

    account.deposit(50);
    REQUIRE(account.get_balance()==50);

    account.withdraw(10);
    REQUIRE(account.get_balance() == 40);
}