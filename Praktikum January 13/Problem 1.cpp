#include <iostream>
using namespace std;

void printArr(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

//int fibb(int n)
//{
//	if (n == 2 || n == 1)
//		return 1;
//	return fibb(n - 1) + fibb(n - 2);
//}
//
//int* fibbArr(int* dest, int n)
//{
//	if (n == 0)
//	{
//		dest[n] = 1;
//		return dest;
//	}
//	else dest[n] = fibb(n + 1);
//	return fibbArr(dest, n - 1);
//}

void fibbnNumbers(int* arr, int n, int index = 1)
{
	if (index == 1)
	{
		arr[0] = 1;
		arr[1] = 1;
		fibbnNumbers(arr, n, index + 1);
	}
	else if (index == n)
		return;
	else 
	{
		arr[index] = arr[index - 1] + arr[index - 2];
		fibbnNumbers(arr, n, index + 1);
	}
}


//int main()
//{
//	int n;
//	cin >> n;
//	int* arr = new int[n];
//	fibbnNumbers(arr, n); // automatic index = 1
//	printArr(arr,n);
//	delete[] arr;
//	return 0;
//}