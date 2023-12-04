#include <iostream>
using namespace std;

void initCols(int**& matrix, size_t row, size_t cols, int*& arrOfSum)
{
	for (size_t col = 0; col < cols; col++)
	{
		cout << "Fill matrix on coordinates " << row << " " << col << " > ";
		cin >> matrix[row][col];
		arrOfSum[row] += matrix[row][col];
	}
}

void initMatrix(int**& matrix, size_t rows, size_t cols, int*& arrOfSum)
{
	for (size_t row = 0; row < rows; row++)
	{
		initCols(matrix, row, cols, arrOfSum);
	}

}

void findBiggestSum(int& biggestSum, int& rowIndex, size_t rows, int* arrOfSum)
{
	for (int row = 0; row < rows; row++)
	{
		if (biggestSum < arrOfSum[row])
		{
			biggestSum = arrOfSum[row];
			rowIndex = row;
		}
	}
}

void printRowWithBiggestSum( int** matrix, int rowIndex,size_t cols, int biggestSum )
{
	cout << "Row with biggest sum("<< biggestSum<<") is row : " << rowIndex << ", with elements : ";
	for (size_t i = 0; i < cols; i++)
	{
		cout << matrix[rowIndex][i] << " ";
	}
}

void userInput(int& cols, int& rows)
{
	while (cols < 1 || rows < 1)
	{
		cout << " Enter natural numbers for number of rows > ";
		cin >> rows;
		cout << " Enter natural numbers for number of columns > ";
		cin >> cols;
	}
}

int main()
{
	int cols = 0, rows = 0;
	userInput(cols, rows);
	int** matrix = new int*[rows];

	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}

	int* arrOfSum = new int[rows];
	for (size_t row = 0; row < rows; row++)
	{
		arrOfSum[row] = 0;
	}

	initMatrix(matrix, rows, cols, arrOfSum);

	int biggestSum = 0, rowIndex = 0;

	findBiggestSum(biggestSum, rowIndex, rows, arrOfSum);

	printRowWithBiggestSum(matrix, rowIndex, cols, biggestSum);

	for (int row = rows - 1 ; row >= 0 ; row--)
	{
			delete[] matrix[row];
	}

	delete[] matrix;
	delete[] arrOfSum;
	return 0;
}