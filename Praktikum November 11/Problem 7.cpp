#include <iostream>
using namespace std;
const int MAX_SIZE = 5;

int findDigitsOfNumber(int number)
{
	int count = 0;
	while (number != 0)
	{
		count++;
		number /= 10;
	}
	return count;
}

void fillArray(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		int a;
		cin >> a;
		arr[i] = a;
	}
}

int fillArrayInNumber(const int arr[], size_t size, int& number)
{
	for (size_t i = 0; i < size; i++)
	{
		(number *= 10) += arr[i];
	}
	return number;
}

void printNumber(int number)
{
	int digitsOfNumber = findDigitsOfNumber(number);
	for (int i = 1; i <= digitsOfNumber; i++)
	{

	}
}

int main()
{
	cout << "Write " << MAX_SIZE << " numbers:" << endl;
	int arr[MAX_SIZE];
	fillArray(arr, MAX_SIZE);
	int number = 0;
	fillArrayInNumber(arr, MAX_SIZE, number);
	cout << number + 1;
	return 0;
}