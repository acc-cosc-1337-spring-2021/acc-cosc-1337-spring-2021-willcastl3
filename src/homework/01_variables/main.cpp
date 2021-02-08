#include "variables.h"
#include <iostream>
#include <iomanip>

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
    double meal_amount, tip_rate, tip_amount, tax_amount, total;

    std::cout << "\n" 
    << "Enter Meal Total: $";
    std::cin >> meal_amount;

    tax_amount = get_sales_tax(meal_amount);

    std::cout << "Enter Tip Rate:   $";
    std::cin >> tip_rate;
    std::cout << "\n";
    
    tip_amount = get_tip_amount(meal_amount, tip_rate);

    total = tip_amount + tax_amount + meal_amount;

    std::cout << "Meal Amount:" 
    << std::setw(2) << "$" << meal_amount << "\n";

    std::cout << "Sales Tax:" 
    << std::setw(4) << "$" << tax_amount << "\n";

    std::cout << "Tip Amount:" 
    << std::setw(3) << "$" << tip_amount << "\n";

    std::cout << "Total:" 
    << std::setw(8) << "$" << total<< "\n";

    return 0;
}
