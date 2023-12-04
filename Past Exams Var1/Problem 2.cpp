#include <iostream>
using namespace std;

void userInputRowsAndCols(int& rows, int& cols)
{
	while (rows < 1 || cols < 1)
	{
		cout << "Enter natural number for rows and cols >";
		cin >> rows >> cols;
	}
}

void userInputMatrixInsideFor(int** matrix, int row, int cols)
{
	for (int col = 0; col < cols; col++)
	{
		cin >> matrix[row][col];
	}
}

void userInputMatrix(int** matrix, int rows, int cols)
{
	for (int row = 0; row < rows; row++)
	{
		userInputMatrixInsideFor(matrix, row, cols);
	}
}

void deleteMatrix(int** matrix, int rows, int cols)
{
	for (size_t row = 0; row < rows; row++)
	{
		delete[] matrix[row];
	}
	delete[] matrix;
}

bool isPrime(int n)
{
	double end = sqrt(n);
	for (size_t i = 2; i <= end; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

bool isTherePrimeInMatrix(int** matrix, int rows, int cols)
{	
	bool foundPrime = false;
	for (int row = 0; row < rows; row++, cols--)
	{
		for (int col = 0; col < cols - 1; col++)
		{
			if (isPrime(matrix[row][col]))
				return true;
		}
	}
	return false;
}

int main()
{
	int rows = 0, cols = 0;
	userInputRowsAndCols(rows, cols);

	int** matrix = new int* [rows];
	for (size_t row = 0; row < rows; row++)
	{
		matrix[row] = new int[cols];
	}

	userInputMatrix(matrix, rows, cols);

	cout << isTherePrimeInMatrix(matrix, rows, cols);

	deleteMatrix(matrix, rows, cols);
	return 0;
}