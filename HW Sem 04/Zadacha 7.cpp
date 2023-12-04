// Zadacha 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isTheNumberSorted(int n)
{

	int temp = n % 10;
	n /= 10;
	int currentLastDigit = n % 10;

	if (temp >= currentLastDigit)
	{
		while (n != 0)
		{
			currentLastDigit = n % 10;
			n /= 10;

			if (temp < currentLastDigit)
				return false;

			temp = currentLastDigit;
		}
		return true;
	}
	else
	{
		while (n != 0)
		{
			currentLastDigit = n % 10;
			n /= 10;

			if (temp > currentLastDigit)
				return false;

			temp = currentLastDigit;
		}
		return true;
	}
}

int main()
{
	int n;
	std::cin >> n;

	if (isTheNumberSorted(n))
	{
		std::cout << "true";
	}
	else
	{
		std::cout << "false";
	}

}

