#include "variables.h"
#include <iostream>
#include <iomanip>

using std::cout;    using std::cin;     using std::setw;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
    double meal_amount, tip_rate, tip_amount, tax_amount, total;

    cout << "\n" << "Enter Meal Total: $";
    cin >> meal_amount;

    tax_amount = get_sales_tax(meal_amount);

    cout << "Enter Tip Rate as decimal: ";
    cin >> tip_rate;
    cout << "\n";
    
    tip_amount = get_tip_amount(meal_amount, tip_rate);

    total = tip_amount + tax_amount + meal_amount;

    cout << "Meal Amount:" << setw(2) << "$" << meal_amount << "\n";

    cout << "Sales Tax:" << setw(4) << "$" << tax_amount << "\n";

    cout << "Tip Amount:" << setw(3) << "$" << tip_amount << "\n";

    cout << "Total:" << setw(8) << "$" << total<< "\n";

    return 0;
}
