#include <iostream>
using namespace std;

bool isPrime(int n)
{
	double end = sqrt(n);
	for (size_t i = 2; i < end; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	cout << isPrime(10);
	return 0;
}