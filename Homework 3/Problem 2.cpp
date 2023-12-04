#include <iostream>
using namespace std;
const int MATRIX_SIZE = 32;

int countOfChecksNeeded(size_t size)
{
	int sum = 0;
	for (int i = 1; i <= size; i++)
	{
		sum += i;
	}
	return sum;
}

bool isRelationOfEquality(int matrix[MATRIX_SIZE][MATRIX_SIZE], size_t size)
{
	int row = 0, col = 0, swaps = 0, colcounter = 0;
	size_t countofSwaps = countOfChecksNeeded(size);
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

int main()
{
	
	return 0;
}