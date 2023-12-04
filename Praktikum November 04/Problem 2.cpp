#include <iostream>

int makeTriangular(int n)
{
	int copy = 0;

	for (int i = 1; i <= n; i++)
	{
		copy += i;
	}

	return copy;
}


void findTriangularNumbers(int n, int& lowerNumber, int& biggerNumber)
{
	for (int i = 1; i <= n; i++)
	{
		if (n >= makeTriangular(i) && n < makeTriangular(i + 1))
		{
			lowerNumber = makeTriangular(i);
			biggerNumber = makeTriangular(i + 1);
		}
	}
}

int main()
{
	int number;
	std::cin >> number;

	int lowerNumber = 0, biggerNumber = 0;
	int& small = lowerNumber;
	int& big = biggerNumber;

	findTriangularNumbers(number, small, big);

	std::cout << small << " + " << big;

	return 0;
}