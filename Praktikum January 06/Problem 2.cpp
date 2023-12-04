#include <iostream>	
using namespace std;

void printMatrix(int** matrix, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void sort(int** matrix, size_t rows, size_t cols)
{
	for (size_t ind = 0; ind < cols; ind++)
	{
		bool wasSwapped = false;
		for (size_t i = 0; i < cols - 1; i++)
		{
			if (matrix[0][i] > matrix[0][i + 1] ||
				(matrix[0][i] == matrix[0][i + 1] && matrix[1][i] > matrix[1][i + 1]))
			{
				swap(matrix[0][i], matrix[0][i + 1]);
				swap(matrix[1][i], matrix[1][i + 1]);
				swap(matrix[2][i], matrix[2][i + 1]);
				wasSwapped = true;
			}
		}
		if (!wasSwapped) return;
	}
}

//int main()
//{
//	int n;
//	cin >> n;
//	n--;
//
//	int** matrix = new int* [3];
//	for (size_t i = 0; i < 3; i++)
//	{
//		matrix[i] = new int[n];
//	}
//
//	for (size_t i = 0; i < 3; i++)
//	{
//		for (size_t j = 0; j < n; j++)
//		{
//			cin >> matrix[i][j];
//		}
//	}
//
//	sort(matrix, 3, n);
//	printMatrix(matrix, 3, n);
//
//
//	for (size_t i = 0; i < 3; i++)
//	{
//		delete[] matrix[i];
//	}
//	delete[] matrix;
//
//	return 0;
//}