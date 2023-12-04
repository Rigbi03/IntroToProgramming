#include <iostream>	
using namespace std;

int findIndex(int* arr, int* arrSecond, size_t arrLength)
{
	int left = 0;
	int right = arrLength;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arrSecond[mid] == -1)
			return mid;
		else if (arrSecond[mid] < arr[mid])
			right = mid - 1;
		else if (arrSecond[mid] > arr[mid])
			left = mid + 1;

		cout << "left " << left << " right " << right << endl;
	}
	return -1;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int secondarr[] = {1,2,3,-1,4,5,6,7,8};
	size_t length = 8;
	cout << findIndex(arr, secondarr, length);
	return 0;
}