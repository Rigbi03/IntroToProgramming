#include <iostream>
using namespace std;

void generateFibArray( int* arr, int n, int index = 1)
{
	if (index == 1)
	{
		arr[0] = 1;
		arr[1] = 1;
		generateFibArray(arr, n, index + 1);
	}
	else if (index == n)
		return;
	else
	{
		arr[index] = arr[index - 1] + arr[index - 2];
		generateFibArray(arr, n, index + 1);
	}
}

bool isFib(int inputNumber, int* fibbArray, int size)
{
	if (inputNumber < 1) 
		return false;

	for (size_t index = 0; index < size; index++)
	{
		if (fibbArray[index] == inputNumber)
			return true;
		else if (fibbArray[index] > inputNumber)
			return false;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;

	int* fibbArray = new int[20];
	generateFibArray(fibbArray, 20);

	cout << isFib(n, fibbArray, 20);
	delete[] fibbArray;
	return 0;
}