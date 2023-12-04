#include <iostream>

void absoluteValue(int& m)
{
	if (m < 0)
		m = -m;
	return;
}

int findNumberOfDigits(int m)
{
	int count = 0;

	while(m!=0)
	{
		m /= 10;
		count++;
	}

	return count;
}

int findTheIndexByPowerOf10(int m, int n)
{
	absoluteValue(m);

	int digitsOfM = findNumberOfDigits(m);
	for (int i = 0; i < digitsOfM; i++)
	{
		if (i == n)
		{
			return m % 10;
		}
		else m /= 10;
	}
	return -1;
}

int main()
{
	int m , n;
	std::cin >> m >> n;
	std::cout << findTheIndexByPowerOf10(m,n);
	return 0;
}