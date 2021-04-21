#include<iostream>
#include "loops.h"

//write using statements for cin and cout

/*
Use a do while loop to prompt the user for
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
using std::cout; using std::cin; using std::string;

int main()
{
    cout<<"****************************************************\n";
    cout<<"This program generates factorial for a given number."<< "\n";
    cout<<"****************************************************\n";

    int user_input;
    char again = 'Y';
    int result;

    do {
        do {
            cout << "\n"
                 << "Enter a number from 1-10: ";

            cin >> user_input;

        } while (!(user_input >= 1 && user_input <= 10));

        result = factorial(user_input);

        cout << "The factorial of " << user_input << " is " << result << ".\n"
             << "\n"
             << "Re-run program(y/n)?";

        cin >> again;

    } while (again == 'Y' || again == 'y');

    return 0;
}

