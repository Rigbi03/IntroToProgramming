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

int reverseNumber(int k)
{
	int reversedNumber = 0;
	while (k != 0)
	{
		(reversedNumber *= 10) += k % 10;
		k /= 10;
	}
	return reversedNumber;
}

int conCatTwoNumbers(int n, int k)
{
	int reversedK = reverseNumber(k);

	if (k == 0)
	{
		return (n *= 10);

	}

	while (reversedK != 0)
	{
		(n *= 10) += reversedK % 10;
		reversedK /= 10;

	}
	return n;
}

bool isSuffix(int n, int k)
{
	while (k != 0)
	{
		int lastDigitOnN = n % 10;
		int lastDigitOfK = k % 10;


		if (lastDigitOnN != lastDigitOfK)
			return false;

		n /= 10;
		k /= 10;
	}
	return true;
}

int findCopiesOfKINN(int n, int k)
{
	int count = 0;
	n /= 10;
	while (findNumberOfDigits(n) >= findNumberOfDigits(k) + 1)
	{
		if (isSuffix(n, k))
			count++;
		n /= 10;
	}
	return count;
}


int main()
{
	int n, k;

	//cin >> n >> k;
	//cout << conCatTwoNumbers(n, k);
	do
	{
		cin >> n >> k;
	} while (n <= 0 || k <= 0 || findNumberOfDigits(n) < findNumberOfDigits(k));

	if (findCopiesOfKINN(n, k) > 0)
	{
		cout << "true";
	}
	else cout << "false";



	return 0;
}