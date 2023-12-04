// Praktikum 21 October.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

int calc(int a[5])
{
	int sum = 7;
	for (int i = 0; a[i]; ++i)
		sum += i;
	return sum;
}




int main()
{
	int* pt;
	int a[3] = { 6,  15,  10 };
	pt = &a[1];
	pt += 1;
	cout << *pt << endl;
	int* arr[10];

	/*int a[7] = { 1, 2, 3 };
	cout << calc(a);*/

	//int a[11];
	//cout << (&a[0] == &a);
	/*cout << (a == &a[0]);
	cout << (a[10] == *(a + 10));
	cout << (*a == a[0]);*/
	//cout << (**a == a[0]);

	/*int a[7] = { 1, 2, 3 };
	cout << calc(a);*/


	//Problem 1
	/*int n;
	std::cin >> n;

	int sum = 0;
	while (n >= 10 || sum >= 10)
	{
		if (sum < 10)
		{
			sum += n % 10;
			n /= 10;

			if (n < 10)
			{
				sum += n;
			}
		}
		else
		{
			n = sum;
			sum = 0;

			while (n > 0)
			{
				sum += n % 10;
				n /= 10;
			}

		}
	}

	std::cout << sum;*/

	//Problem 2
	/*int n;
	std::cin >> n;

	for (int i = 2; i <= n; i++)
	{

	}*/

	//Problem 3
	/*int n;
	std::cin >> n;

	for (int i = 1; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			std::cout << i << " ";
		}
	}
	std::cout << n;*/


	//Problem 4
	/*int n;
	std::cin >> n;

	int result = 1;

	while (n != 0)
	{
		result *= n;
		n--;
	}
	std::cout << result;*/

	//Problem 5
	/*for (int i = 100; i < 1000; i++)
	{
		int sum = (i % 10) + ((i / 10) % 10) + (i / 100);

		bool isPrime = true;
		double sqrtFromSum = sqrt(sum);

		for (int j = 2; j <= sqrtFromSum; j++)
		{
			if (sum % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if ((sum > 9 && sum < 100) && isPrime == true)
		{
			std::cout << i << std::endl;
		}
	}*/

	//Problem 6 NOT FINISHED
	/*while (true)
	{
		int num;
		std::cin >> num;
		int sumOfNumbersOfNum = 0;
		int numCopy = num;

		while (numCopy >= 10)
		{
			sumOfNumbersOfNum += numCopy % 10;
			numCopy /= 10;
			if (numCopy < 10)
			{
				sumOfNumbersOfNum += numCopy;
			}
		}

		if ((num + sumOfNumbersOfNum) % 10 != 0)
		{
			std::cout << "Bad number" << std::endl;
		}
		else
		{
			std::cout << "Perfect number" << std::endl;
			break;
		}
	}*/


	//int found = 0, count = { 6 };

	//// b =>
	//cout << "B; while(A){B}" << endl;
	//int i = 0;
	//int a = 0;
	//cout << (i+=6) << endl;
	//while (a++ < 10)
	//{
	//	cout << (i += 6) << endl;
	//}


	//cout << "do{B}while(A)" << endl;
	//i = 0;
	//a = 0;
	//do
	//{
	//	cout << (i += 6) << endl;
	//} while (a++ < 10);



}