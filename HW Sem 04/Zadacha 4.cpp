// Zadacha 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int reverse(unsigned int n)
{
	int reversedNumber = 0;

	while (n != 0)
	{
		unsigned int lastDigit = n % 10;
		(reversedNumber *= 10) += lastDigit;
		n /= 10; //removes the last digit
	}
	return reversedNumber;

}

int conCatTwoNumbers(int n, int k)
{
	k = reverse(k);

    while (k != 0)
    {
        n *= 10;
		n += k % 10;
		k /= 10;
    }
	return n;
}

int main()
{
	int n, k;
	std::cin >> n >> k;
	std::cout << conCatTwoNumbers(n, k);
}

