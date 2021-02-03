#include "types.h"
#include <iostream>

int main() 
{
	int num;
	std::cout <<"Enter number to multiply: "; 
	std::cin >> num;

 	int result;
	result = multiply_numbers(num);
	std::cout << "The result is: " << result << '\n';

	int num1 = 4;
	result = multiply_numbers(num1);
	std::cout << "The result is: " << result;

	return 0;
}

