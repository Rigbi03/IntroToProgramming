#include <iostream>
using namespace std;

int countDigits(int n)
{
	int count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return count;
}

unsigned int toBinary(unsigned int n)
{
	int result = 0;
	int mult = 1;
	while (n != 0)
	{
		if (n % 2 == 1)
			result += mult;
		mult *= 10;
		n /= 2;
	}
	return result;
}

int toDecimal(int n)
{
	int sum = 0;
	int i = 0;
	while(n!=0)
	{
		if (n % 10 == 1) //101 % 10 = 1
		{
			sum += (1 << i);
		}
		n /= 10;
		i++;
	}
	return sum;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int newNumber = (toBinary(n) ^ (1 << k));
	cout << toDecimal(newNumber);
	return 0;
}