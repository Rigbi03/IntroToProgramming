#include <iostream>
using namespace std;
const size_t MAX_SIZE = 1024;

void printArr(const int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void arrayInput(int arr[], size_t size)
{
	int input = 0;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter Number > ";
		cin >> input;
		arr[i] = input;
	}
}

void indexInput(int& i, int& j, size_t size)
{
	while (i<0 || i> size - 1 || j<0 || i> size - 1)
	{
		cout << "Enter index i > ";
		cin >> i;
		cout << "Enter index j > ";
		cin >> j;
	}
}

void rearrangeRToL(int newIndex, int oldIndex, int arr[], size_t size)
{
	printArr(arr, size);

	if (newIndex > oldIndex)
		swap(oldIndex, newIndex);

	swap(arr[oldIndex], arr[newIndex]);

	while (oldIndex != newIndex + 1)
	{
		printArr(arr, size);
		swap(arr[oldIndex], arr[oldIndex - 1]);
		oldIndex--;
	}
}
void rearrangeLToR()
{

}


int main()
{
	int arr[MAX_SIZE];
	int size = 0, i = -1, j = -1;
	cout << "Enter Size > ";
	cin >> size;
	arrayInput(arr, size);
	indexInput(i, j, size);
	if(i < j)
	rearrangeRToL(i, j, arr, size);
	else if (i > j)
		rearrangeRToL(j, i, arr, size);
	printArr(arr, size);
}