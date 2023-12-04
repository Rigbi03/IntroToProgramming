#include <iostream>
using namespace std;

int replaceFive(unsigned number)
{
	if (number == 0)
		return 0;

	int lastDigit = number % 10;
	if (lastDigit == 5)
		lastDigit = 8;
	return replaceFive(number / 10) * 10 + lastDigit;
}

int main()
{
	cout << replaceFive(5555555);
}