#include <iostream>
using namespace std;
const int SIZE = 1024;

bool isPrime(int number)
{
	int end = sqrt(number);
	for (int i = 2; i <= end; i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}

int findAllProblemsWithIndex(const int arr[], int size, int index)
{
	int count = 0;
	for (int j = index + 1; j < size - 1; j++)
	{
		if ((isPrime(arr[index]) && !isPrime(arr[j])) ||
			(isPrime(arr[index]) && isPrime(arr[j]) && arr[index] > arr[j]))
			count++;
	}
	return count;
}

int findAllProblems(const int arr[], int size)
{
	int count = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (isPrime(arr[i]))
			count += findAllProblemsWithIndex(arr, size, i);
	}
	return count;
}

int main()
{
	int length = 0, array[SIZE];

	while (length < 1)
	{
		cout << "length > ";
		cin >> length;
	}

	int index = 0;

	while (length != 0)
	{
		int input;
		cin >> input;
		if (input > 1)
		{
			array[index] = input;
			index++;
			length--;
		}
	}
	length = index + 1;
	cout << findAllProblems(array, length);


	return 0;
}