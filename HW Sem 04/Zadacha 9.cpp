// Zadacha 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int occurrenceOfNumber(int digit, int n)
{
	int count = 0;

	while (n != 0)
	{
		if (digit == n % 10)
		{
			count++;
		}
		n /= 10;
	}

	return count;
}

int sortNumber(int n)
{
	//int digitsOfN = numberOfDigitsOf(n);
	int sortedNumber = 0;

	for (int i = 0; i <= 9; i++)
	{
		int countOfCurrentDigit = occurrenceOfNumber(i, n);

		while (countOfCurrentDigit != 0)
		{
			sortedNumber += i;
			sortedNumber *= 10;
			countOfCurrentDigit--;
		}
	}

	return (sortedNumber / 10);
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << sortNumber(n);
	return 0;
}
