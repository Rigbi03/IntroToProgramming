#include <iostream>
using namespace std;


int absoluteValue(int number)
{
	return number < 0 ? -number : number;
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
int countDigits(int number)
{
	number = absoluteValue(number);
	int count = 0;
	while (number != 0)
	{
		count++;
		number /= 10;
	}
	cout << "number of Digits = " << count << endl;
	return count;
}
bool sumHasRepetitiveDigits(int number)
{
	while (number > 9)
	{
		int lastDigit = number % 10;
		number /= 10;
		int secondToLastDigit = number % 10;

		if (lastDigit == secondToLastDigit)
			return true;
	}
	return false;
}
int findDigitByIndex(int number, int index, int digitsOfNumber)
{
	number = absoluteValue(number);
	index = absoluteValue(index);
	int searchedDigit = 0;

	for (int i = 1; i <= digitsOfNumber; i++)
	{
		if (digitsOfNumber - i + 1 == index)
		{
			searchedDigit = (number / powerOf(10, i - 1)) % 10;
			cout << "i " << i << endl;
		}
	}

	return searchedDigit;
}
int sumAllSubNumbers(int number)
{
	number = absoluteValue(number);
	int digitsOfNumber = countDigits(number), sum = 0;
	for (int i = 1; i <= digitsOfNumber; i++)
	{
		sum += findDigitByIndex(number, i, digitsOfNumber);
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
	cout << sumAllSubNumbers(1234) << endl;
	cout << "power oF 10 " << powerOf(10, 3);
	return 0;
}