#include <iostream>
using namespace std;

void initArray(int*& array, int n)
{
	int input;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		array[i] = input;
	}
}

void initArray(bool*& array, int n)
{
	int input;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		array[i] = input;
	}
}

int count1s(const bool* boolArray, int size)
{
	int count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (boolArray[i])
			count++;
	}
	return count;
}

void compareArrays(const int* initialArray, const bool* boolArray, int size, int*& newArray)
{
	int indexInNewArray = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (boolArray[i])
			newArray[indexInNewArray++] = initialArray[i];
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
	int* initialArray = new int[n];
	bool* boolArray = new bool[n];

	initArray(initialArray, n);
	initArray(boolArray, n);

	int numberOf1s = count1s(boolArray, n);
	int* newArray = new int[numberOf1s];

	compareArrays(initialArray, boolArray, n, newArray);
	printArray(newArray, numberOf1s);

	delete[] initialArray;
	delete[] boolArray;
	delete[] newArray;
	return 0;
}