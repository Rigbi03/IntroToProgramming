#include <iostream>
using namespace std;


void quickSort(int* a, int n) 
{
	int leftIndex = 0, rightIndex = n - 1;
	int x = a[rightIndex / 2];

	do {
		while (a[leftIndex] < x) 
			leftIndex++;

		while (a[rightIndex] > x) 
			rightIndex--;

		if (leftIndex < rightIndex) {
			swap(a[leftIndex], a[rightIndex]);
			leftIndex++;
			rightIndex--;
		}
		else if (leftIndex == rightIndex) {
			leftIndex++; rightIndex--;
		}

	} while (leftIndex <= rightIndex);

	if (rightIndex > 0) 
		quickSort(a, rightIndex + 1);

	if (leftIndex < n - 1) 
		quickSort(a + leftIndex, n - leftIndex);
}