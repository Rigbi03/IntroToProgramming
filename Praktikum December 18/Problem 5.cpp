#include <iostream>
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

void deleteMatrix(int**& matrix, int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void getSumAboveDiagCols(int** matrix, int row, int cols, int& sum)
{
	for (int col = 0; col < cols - 1; col++)
	{
		sum += (matrix[row][col] % 2 == 0) ? matrix[row][col] : 0;
		cout << "Current num above diag > " << matrix[row][col] << endl;
	}
}

int getSumAboveDiag(int** matrix, int rows, int cols)
{
	int sum = 0;
	for (int row = 0; row < rows - 1; row++)
	{
		getSumAboveDiagCols(matrix, row, cols, sum);
		cols--;
	}
	return sum;
}

void getSumBelowDiagCols(int** matrix, int row, int rows, int cols, int& sum)
{
	for (int col = cols - 1; col > rows - row - 2; col--)
	{
		sum += (matrix[row][col] % 2 != 0) ? matrix[row][col] : 0;
		cout << "Current num below diag > " << matrix[row][col] << endl;
	}
}

int getSumBelowDiag(int** matrix, int rows, int cols)
{
	int sum = 0;

	for (int row = 0; row < rows; row++)
	{
		getSumBelowDiagCols(matrix, row, rows, cols, sum);

	}

	return sum;
}

int getSumOnOppositeDiag(int** matrix, int rows, int cols)
{
	int sum = 0;

	for (int row = 0, col = cols - 1; row < rows && col >= 0; row++, col--)
	{
		sum += (matrix[row][col] * matrix[row][col]);
		cout << "Current num on opposite diag > " << matrix[row][col]*matrix[row][col] << endl;
	}

	return sum;
}

int main()
{
	int n = 0;
	while (n < 1)
		cin >> n;

	int** matrix = new int* [n];

	for (size_t i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}

	initMatrix(matrix, n, n);

	cout << "Sum above Diag = " << getSumAboveDiag(matrix, n, n) << endl;
	
	cout << "Sum below Diag = " << getSumBelowDiag(matrix, n, n) << endl;

	cout << "Sum on opposite Diag = " << getSumOnOppositeDiag(matrix, n, n) << endl;

	deleteMatrix(matrix, n);
	return 0;
}