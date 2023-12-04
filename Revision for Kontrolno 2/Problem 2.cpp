#include <iostream>
using namespace std;





bool numberHasRepetitiveDigits(int number)
{
	int hist[10] = {0};

	while (number)
	{
		hist[number % 10] ++;
		number /= 10;
	}

	for (size_t i = 0; i < 10; i++)
	{
		if (hist[i] > 1)
			return true;
	}
	return false;
}

void goThroughLowerHalf(int** matrix, int rows, int cols)
{
	for (int row = rows - 1; row >= 0; row--)
	{
		int currentRow = row, col = 0;
		while (row < rows && col <= rows - currentRow)
		{
			if (numberHasRepetitiveDigits(matrix[row][col]))
				cout << matrix[row][col] << " ";
			row++, col++;
		}
		row = currentRow;
	}
}

void goThroughUpperHalf(int** matrix, int rows, int cols)
{
	for (int col = 1; col < cols; col++)
	{

	}
}

int main()
{
	int n = 0;
	while (n < 1 || n > 30)
		cin >> n;

	int** matrix = new int* [n];
	for (size_t row = 0; row < n; row++)
	{
		matrix[row] = new int[n];
	}

	for (size_t row = 0; row < n; row++)
	{
		for (size_t col = 0; col < n ; col++)
		{
			cin >> matrix[row][col];
		}
	}
	
	goThroughLowerHalf(matrix, n, n);
	for (size_t row = 0; row < n; row++)
	{
		delete[] matrix[row];
	}
	delete[] matrix;
	return 0;
}