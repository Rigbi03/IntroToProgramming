#include <iostream>
using namespace std;

void userInputRowsAndCols(int& rows, int& cols)
{
	while (rows < 1 || cols < 1)
	{
		cout << "Enter natural numbers for rows and cols >";
		cin >> rows >> cols;
	}
}

void deleteMatrix(int** matrix, int rows)
{
	for (size_t row = 0; row < rows; row++)
	{
		delete[] matrix[row];
	}
	delete[] matrix;
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

	deleteMatrix(matrix, rows);
	return 0;
}