// Zadacha 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isTheNumberDigitsEqual(int n)
{
	int currentDigit = n % 10;
	n /= 10;

	while (n != 0)
	{
		if (currentDigit != n % 10)
		{
			return false;
		}

		n /= 10;
		currentDigit = n % 10;
	}
	return true;
}

int main()
{
	int n;
	std::cin >> n;

	if (isTheNumberDigitsEqual(n))
	{
		std::cout << "true";
	}
	else std::cout << false;
	
	return 0;
}
