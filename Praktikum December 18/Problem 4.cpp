#include<iostream>
using namespace std;

void initMatrixCols(int** matrix, int row, int cols, int input)
{
	for (int col = 0; col < cols; col++)
	{
		cin >> input;
		matrix[row][col] = input;
	}

}

void initMatrix(int** matrix, int rows, int cols)
{
	int input = 0;
	for (int row = 0; row < rows; row++)
	{
		initMatrixCols(matrix, row, cols, input);
	}
}

void printMatrixCols(int** matrix, int row, int cols)
{
	for (int col = 0; col < cols; col++)
	{
		if (matrix[row][col] % 2 == 0)
			cout << "*" << " ";
		else cout << matrix[row][col] << " ";
	}
}

void printMatrix(int** matrix, int rows, int cols)
{
	for (int row = 0; row < rows; row++)
	{
		printMatrixCols(matrix, row, cols);
		cout << endl;
	}
}

void deleteMatrix(int**& matrix, int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{
	int rows = 0, cols = 0;
	while (rows < 1 || cols < 1)
		cin >> rows >> cols;
	
	int** matrix = new int* [rows];

	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}

	initMatrix(matrix, rows, cols);

	printMatrix(matrix, rows, cols);

	deleteMatrix(matrix, rows);
	
	return 0;
}