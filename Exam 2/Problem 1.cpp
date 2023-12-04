#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

void deleteMatrix(int** matrix, int rows)
{
	for (int row = 0; row < rows; row++)
	{
		delete[] matrix[row];
	}
	delete[] matrix;
}

int findBiggestY(int** matrix, int rows)
{
	int max = 0;
	for (size_t row = 0; row < rows; row++)
	{
		max = (max < matrix[row][1]) ? matrix[row][1] : max;
	}
	return max;
}

//int main()
//{
//	int pointsNumber = 0;
//
//	while (pointsNumber < 1)
//	{
//		cout << "Enter a natural number for pointsNumber > ";
//		cin >> pointsNumber;
//	}
//
//	int** matrix = new int* [pointsNumber];
//	for (size_t i = 0; i < pointsNumber; i++)
//	{
//		matrix[i] = new int[2];
//	}
//
//	for (size_t row = 0; row < pointsNumber; row++)
//	{
//		cout << "Enter X" << row << " >";
//		cin >> matrix[row][0];
//		cout << "Enter Y" << row << " >";
//		cin >> matrix[row][1];
//	}
//
//	deleteMatrix(matrix, pointsNumber);
//	return 0;
//}