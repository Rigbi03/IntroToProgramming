#include <iostream>
using namespace std;

void userInputForSize(int& size)
{
	while (size < 1 )
	{
		cout << "Enter natural number for rows and columns >";
		cin >> size ;
	}
}

void userInputMatrixInsideFor(int** matrix, int row, int cols)
{
	for (size_t col = 0; col < cols; col++)
	{
		cin >> matrix[row][col];
	}
}

void userInputMatrix(int** matrix, int rows, int cols)
{
	cout << "Enter Matrix >" << endl;
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

int findMaxElementInMatrix(int** matrix, int rows, int cols)
{
	int max = 0;
	for (size_t row = 0; row < rows; row++)
	{
		for (size_t col = 0; col < cols; col++)
		{
			max = (max < matrix[row][col]) ? matrix[row][col] : max;
		}
	}
	return max;
}

void generateFibArray(int* arr, int n, int index = 1)
{
	if (index == 1)
	{
		arr[0] = 1;
		arr[1] = 1;
		generateFibArray(arr, n, index + 1);
	}
	else if (index == n)
		return;
	else
	{
		arr[index] = arr[index - 1] + arr[index - 2];
		generateFibArray(arr, n, index + 1);
	}
}

bool isFib(int inputNumber, int* fibbArray, int size)
{
	if (inputNumber < 1)
		return false;

	for (size_t index = 0; index < size; index++)
	{
		if (fibbArray[index] == inputNumber)
			return true;
		else if (fibbArray[index] > inputNumber)
			return false;
	}
	return false;
}

bool isThereFibAboveSecondaryDiag(int** matrix, int rows, int cols, int* fibbArr, int fibbArrSize)
{
	for (size_t row = 0; row < rows; row++, cols--)
	{
		for (size_t col = 0; col < cols; col++)
		{
			if (isFib(matrix[row][col], fibbArr, fibbArrSize))
				return true;
		}
	}
	return false;
}

int main()
{
	int size = 0;
	userInputForSize(size);

	int** matrix = new int* [size];
	for (size_t row = 0; row < size; row++)
	{
		matrix[row] = new int[size];
	}
	
	userInputMatrix(matrix, size, size);
	
	int maxElement = findMaxElementInMatrix(matrix, size, size);
	int* fibbArr = new int[maxElement];
	generateFibArray(fibbArr, maxElement);

	cout << isThereFibAboveSecondaryDiag(matrix, size, size, fibbArr, maxElement);

	delete[] fibbArr;
	deleteMatrix(matrix, size);
	return 0;
}