#include <iostream>
using namespace std;

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
int absoluteValue(int number)
{
	return number < 0 ? -number : number;
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
int occurencesOfDigitInNumber(int digit, int number)
{
	number = absoluteValue(number);
	int count = 0;
	while (number != 0)
	{
		if (number % 10 == digit)
			count++;
		number /= 10;
	}
	return count;
}
bool numberContainsDigit(int number, int digit)
{
	number = absoluteValue(number);
	while (number != 0)
	{
		if (number % 10 == digit)
			return true;
		number /= 10;
	}
	return false;
}
int removeDigitRepetitions(int digit, int number)
{
	number = absoluteValue(number);
	int tempNumber = 0, found = 0, index = 0, copyOfNumber = number;
	while (copyOfNumber != 0)
	{
		if (copyOfNumber % 10 == digit && found == 0)
			found++;
		else if (copyOfNumber % 10 == digit && found != 0)
		{
			tempNumber = number % (powerOf(10, index));
			number /= (powerOf(10, index + 1)); //remove repetitive digit
			(number *= powerOf(10, countDigits(tempNumber))) += tempNumber;
		}
		copyOfNumber /= 10;
		index++;
	}
	return number;
}
int removeRepetetiveDigits(int number)
{
	int digitsOfNumber = countDigits(number);
	int tempNumber = 0;
	int copyOfNumber = number;
	while (copyOfNumber != 0)
	{
		int lastDigit = copyOfNumber % 10;
		if (occurencesOfDigitInNumber(lastDigit, number) > 1)
		{
			number = removeDigitRepetitions(lastDigit, number);
		}
		copyOfNumber /= 10;

	}
	return number;
}
int commonDigits(int searchedNumber, int lookedInNumber)
{
	searchedNumber = absoluteValue(searchedNumber);
	lookedInNumber = absoluteValue(lookedInNumber);
	int count = 0;
	int digitsOfSearchedNumber = countDigits(searchedNumber);
	for (int i = 1; i <= digitsOfSearchedNumber; i++)
	{
		if (numberContainsDigit(lookedInNumber, (searchedNumber % 10)))
			count++;
		searchedNumber /= 10;
	}
	return count;

}

int main()
{
	int num1, num2;
	cout << "Enter 2 numbers > ";
	cin >> num1 >> num2;
	num1 = absoluteValue(num1);
	num1 = removeRepetetiveDigits(num1);
	num2 = absoluteValue(num2);
	num2 = removeRepetetiveDigits(num2);

	if (commonDigits(num1, num2) < countDigits(num1) && commonDigits(num2, num1) < countDigits(num2))
	{
		cout << "Not Comparable";
	}
	else if (commonDigits(num1, num2) < countDigits(num2))
	{
		cout << "First is Weaker";
	}
	else if (commonDigits(num2, num1) < countDigits(num1))
	{
		cout << "Second is Weaker";
	}
	else if (commonDigits(num1, num2) == countDigits(num1) && commonDigits(num2, num1) == countDigits(num2))
	{
		cout << "Equal strength";
	}



}