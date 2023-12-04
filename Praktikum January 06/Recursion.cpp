#include <iostream>
using namespace std;

bool isPalindrome(const char* str, int i, int j)
{

	if (str[i] != str[j]) return false;

	if (i >= j) return true;

	isPalindrome(str, i + 1, j - 1);
}

void swap(int* arr, int x, int y, size_t size, int index)
{
	if (arr[index] == x) arr[index] = y;
	if (index == size - 1) return;

	swap(arr, x, y, size, index + 1);
}

int main()
{
	int arr[] = { 1,2,3,4,5,5,4,3,2,1 };
	swap(arr , 2, 9, 10, 0);

	for (size_t i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}