#include <iostream>
using namespace std;

bool wayExists(int* arr,int size, int start)
{

	if (start >= size || start < 0) return false;

	int currentPossibleSteps = arr[start];

	if (arr[start] == 0) return true;

	arr[start] = size + 1; //Marked

	return  wayExists(arr, size, start + currentPossibleSteps) ||
		wayExists(arr, size, start - currentPossibleSteps);
}

//int main()
//{
//	bool thereIsNo0 = true;
//	int n, startIndex;
//	cin >> n;
//	int* arr = new int[n];
//
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//		if (arr[i] == 0) thereIsNo0 = false;
//	}
//
//	cin >> startIndex;
//	cout << wayExists(arr,n,startIndex);
//
//	delete[] arr;
//	return 0;
//}