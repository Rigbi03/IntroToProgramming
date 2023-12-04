#include <iostream>
using namespace std;

bool isDigit(int num)
{
	return num >= 0 && num <= 9;
}

void validateNumberIsDigit(int** matrix, int row, int col)
{

	while (!isDigit(matrix[row][col]))
	{
		std::cout << "You have enter a number, which is greater than 9 or lower than 0, please re-enter >";
		std::cin >> matrix[row][col];
	}

}

void printArr(int* arr, int size)
{
	for (size_t index = 0; index < size; index++)
	{
		std::cout << arr[index] << " ";
	}
	std::cout << endl;
}

void userInputForSize(int& rows, int& cols)
{
	while (rows < 1 || cols < 10)
	{
		std::cout << "Enter natural number for rows (Bigger than 0) and columns (Bigger than 9) >";
		std::cin >> rows >> cols;
	}
}

void userInputMatrixInsideFor(int** matrix, int row, int cols)
{
	for (int col = 0; col < cols; col++)
	{
		cin >> matrix[row][col];

		if (matrix[row][col] > 9 || matrix[row][col] < 0)
			validateNumberIsDigit(matrix, row, col);
	}
}

void userInputMatrix(int** matrix, int rows, int cols)
{
	std::cout << "Enter Matrix of only DIGITS >" << endl;
	for (int row = 0; row < rows; row++)
	{
		userInputMatrixInsideFor(matrix, row, cols);
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

void initializeArrInsideFor(int* arr, int size, int** matrix, int row, int cols)
{
	for (size_t col = 0; col < cols; col++)
	{
		(arr[col] *= 10) += matrix[row][col];
	}
}

void initializeArr(int* arr, int size, int** matrix, int rows, int cols)
{
	for (int row = rows - 1; row >= 0; row--)
	{
		initializeArrInsideFor(arr, size, matrix, row, cols);
	}
}

int main()
{
	int rows = 0, cols = 0;
	userInputForSize(rows, cols);

	int** matrix = new int* [rows];
	for (size_t row = 0; row < rows; row++)
	{
		matrix[row] = new int[rows];
	}
	userInputMatrix(matrix, rows, cols);

	int* arr = new int[cols] {0};
	initializeArr(arr, cols, matrix, rows, cols);

	printArr(arr, cols);

	delete[] arr;
	//deleteMatrix(matrix, rows);
	return 0;
}