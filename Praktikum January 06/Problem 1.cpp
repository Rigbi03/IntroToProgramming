#include <iostream>	
using namespace std;

void print(int* array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}


void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


void rightToLeftBubble(int* array, size_t size, size_t ind, bool& wasSwapped)
{
	for (size_t j = size - 1 - ind; j > ind; j--)
	{
		if (array[j] < array[j - 1])
		{
			swap(array[j], array[j - 1]);
			wasSwapped = true;
		}
	}
}

void leftToRightBubble(int* array, size_t size, bool& wasSwapped)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			swap(array[i], array[i + 1]);
			wasSwapped = true;
		}
	}
}

void cocktailShaker(int* array, size_t size)
{
	for (size_t ind = 0; ind < size/2; ind++)
	{
		bool wasSwapped = false;

		leftToRightBubble(array, size, wasSwapped);

		rightToLeftBubble(array, size, ind, wasSwapped);

		if (!wasSwapped) return;
	}
}



//int main()
//{
//	int array[] = { 5,6,3,2,4,1 };
//	cocktailShaker(array, 6);
//	print(array, 6);
//	return 0;
//}