#include <iostream>
using namespace std;

int findNumberOfDigits(int n)
{
	int count = 0;

	while (n != 0)
	{
		n /= 10;
		count++;
	}

	return count;
}

bool isAdjacent(int n)
{
	int digitsOfN = findNumberOfDigits(n);

	for (int i = 1; i <= digitsOfN - 1; i++)
	{
		int copyOfN = n;
		int lastDigit = n % 10;
		int secondToLastDigit = (n / 10) % 10;

		if (lastDigit == secondToLastDigit)
			return false;
		n /= 10;
	}
	return true;
}

int main()
{
	int a, b;

	do
	{
		cin >> a >> b;
	} while (a <= 0 || b <= 0);

	int max = 0, min = 0;

	for (int i = a; i <= b; i++)
	{
		if (isAdjacent(i) && min == 0)
		{
			min = i;
		}

		if (isAdjacent(i) && i >= max)
		{
			max = i;
		}

	}

	if (max == 0 && min == 0)
	{
		cout << "No adjacent numbers!";
	}
	else
	{
		cout << (max - min) << endl;
	}
	return 0;
}