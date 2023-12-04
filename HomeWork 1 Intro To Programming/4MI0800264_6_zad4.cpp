#include <iostream>
using namespace std;


int absoluteValue(int number)
{
	return number < 0 ? -number : number;
}
int countDigits(int number)
{
	int count = 0;
	while (number != 0)
	{
		count++;
		number /= 10;
	}
	return count;
}
bool numberContainsDigit(int number, int digit)
{
	while (number != 0)
	{
		if (number % 10 == digit)
			return true;
		number /= 10;
	}
	return false;
}
bool numberHasRepetitiveDigits(int number)
{
	while (number != 0)
	{
		int lastDigit = number % 10;
		number /= 10;

		if (numberContainsDigit(number, lastDigit))
			return true;
	}

	return false;
}
int countDigits(int number)
{
	number = absoluteValue(number);
	int count = 0;
	while (number != 0)
	{
		count++;
		number /= 10;
	}
	return count;
}
int powerOf(int number, int power)
{
	int mult = number;
	while (power > 1)
	{
		number *= mult;
		power--;
	}
	return number;
}
int findSubNumber(int number, int mask)
{
	int sum = 0, mult = 1;

	while (number != 0)
	{
		if (mask % 2 == 1)
		{
			sum += (mult * (number % 10));
			mult *= 10;
		}

		mask /= 2;
		number /= 10;
	}
	return sum;
}
int sumAllSubNumbers(int number)
{
	int digitsOfNumber = countDigits(number), countOfNumbers = powerOf(2, digitsOfNumber), sum = 0;

	for (int i = 0; i < countOfNumbers; i++)
	{
		int subNumber = findSubNumber(number, i);
		if (!numberHasRepetitiveDigits(subNumber))
			sum += subNumber;
	}
	return sum;
}

int main()
{
	int number = 0;

	while (number < 1)
	{
		cout << "Enter Natural Number > ";
		cin >> number;
	}
	cout << sumAllSubNumbers(number);
	return 0;
}