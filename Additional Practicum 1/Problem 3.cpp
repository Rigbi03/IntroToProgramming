#include <iostream>
using namespace std;
/*const size_t MAX_SIZE = 1024;
void printArr(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}
int arr[MAX_SIZE];
	//findCompositeNumbers(arr, endNum, numbersInArray);
	printArr(arr, numbersInArray);

	void findCompositeNumbers(int arr[], int endNum, int& arrayNumbers)
{

	for (int i = 1, arrIndex = 0; i < endNum; i++)
	{
		if (isComposite(i))
		{
			arr[arrayNumbers] = i;
			arrayNumbers++;
		}
	}
}*/

bool isComposite(int num)
{
	double endNum = sqrt(num);
	for (int i = 2; i <= endNum; i++)
	{
		if (num % i == 0)
			return true;
	}
	return false;
}

void findCompositeNumbers(int endNum)
{
	for (int i = 1, arrIndex = 0; i < endNum; i++)
	{
		if (isComposite(i))
		{
			cout << i << " ";
		}
	}
}


int main()
{
	int endNum = 0;

	while (endNum < 1)
	{
		cout << "Enter Natural Number > ";
		cin >> endNum;
	}
	findCompositeNumbers(endNum);
	return 0;
}