#include <iostream>
using namespace std;
const int MATRIX_SIZE = 32;

int countOfSwapsNeeded(size_t size)
{
	int sum = 0;
	for (int i = 1; i <= size; i++)
	{
		sum += i;
	}
	return sum;
}

void swap(int& el1, int& el2)
{
	int temp = el1;
	el1 = el2;
	el2 = temp;
}

void transpose(int matrix[MATRIX_SIZE][MATRIX_SIZE], size_t size)
{
	int row = 0, col = 0, swaps = 0, colcounter = 0;
	size_t countofSwaps = countOfSwapsNeeded(size); 
	while (swaps != countofSwaps)
	{
		if (col >= size)
		{
			colcounter++;
			col = colcounter;
			row++;
		}

		swap(matrix[row][col], matrix[col][row]);
		swaps++;
		col++;
	}
}

void printMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], size_t size)
{
	for (int rowIndex = 0; rowIndex < size; ++rowIndex) {
		for (int colIndex = 0; colIndex < size; ++colIndex) {
			std::cout << matrix[rowIndex][colIndex] << " ";
		}
		std::cout << std::endl;
	}

}

void ManuallyFillMatrix(int matrix[][MATRIX_SIZE], size_t size)
{
	cout << "Please fill the "<< size << " by " << size << " Matrix > " << endl;
	for (int rowIndex = 0; rowIndex < size; ++rowIndex) {
		for (int colIndex = 0; colIndex < size; ++colIndex) {
			cin >> matrix[rowIndex][colIndex];
		}
		std::cout << std::endl;
	}
}

int main()
{
	size_t size = 0;
	int matrix[MATRIX_SIZE][MATRIX_SIZE];

	while (size < 1)
	{
		cout << "Enter matrix size > ";
		cin >> size;
	}

	ManuallyFillMatrix(matrix, size);
	transpose(matrix, size);
	printMatrix(matrix, size);
	return 0;
}