#include <iostream>
using namespace std;

void userInput

int main()
{
	int n = 0;
	while (n < 1)
	{
		cin >> n;
	}

	int** matrix1 = new int* [n];
	for (size_t i = 0; i < n; i++)
	{
		matrix1[i] = new int[n];
	}

	for (size_t row = 0; row < n; row++)
	{
		for (size_t col = 0; col < n; col++)
		{
			cin >> matrix1[row][col];
		}
	}

	return 0;
}