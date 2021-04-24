
class BankAccount{

friend void friend_display_balance(const BankAccount& account);

public: // acess specifiers
    BankAccount(): BankAccount(1000){} //synthesized default constructor
    explicit BankAccount(int b) : balance(b){}
    [[nodiscard]] int get_balance()const{return balance;}
    int deposit(int amount);
    int withdraw(int amount);

private:
    int balance{0};
    static int bank_balance;
};

//FREE FUNCTIONS- NOT PART OF THE BANK ACCOUNT CLASS

void display_balance(BankAccount account);
BankAccount get_account(int balance);
