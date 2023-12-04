#include <iostream>
using namespace std;

void initArray(int*& array, int n, int firstHalfIndex, int secondHalfIndex)
{
	int input;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		if (i % 2 == 0)
		{
			array[firstHalfIndex++] = input;
		}
		else array[secondHalfIndex++] = input;
	}
}

void printArray(const int* array, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

int main()
{
	int n = 0;
	while(n < 1)
	cin >> n;
	int* array = new int[n];
	int firstHalfIndex = 0, secondHalfIndex = (n % 2 == 0) ? n/2 : n/2 + 1;
	
	initArray(array, n, firstHalfIndex, secondHalfIndex);
	printArray(array, n);
	
	delete[] array;
	return 0;
}