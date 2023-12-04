#include <iostream>	
using namespace std;

void countInversionsInsideFor(int* array, size_t size, size_t i, int& count, bool& noInversions)
{
	for (size_t j = i; j < size; j++)
	{
		if (array[i] > array[j])
		{
			count++;
			noInversions = false;
		}
	}
}

int countInversions(int* array, size_t size)
{
	int count = 0;
	for (size_t i = 0; i < size; i++)
	{
		bool noInversions = true;
		countInversionsInsideFor(array, size, i, count, noInversions);
		if (noInversions) return count;
	}
	return count;
}

//int main()
//{
//	int array[] = { 6,5,4,3,2,1 };
//	cout << countInversions(array, 6);
//	return 0;
//}