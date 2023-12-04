#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

bool isLetter(char ch)
{
	return (ch <= 'z' && ch >= 'a') || (ch >= 'A' && ch <= 'Z');
}

void userInputRowsAndCols(int& rows, int& cols)
{
	while (rows < 1 || cols < 1)
	{
		cout << "Enter natural number for rows and cols >";
		cin >> rows >> cols;
	}
	cin.ignore();
}




int main()
{
	int rows = 0, cols = 0;
	char str[100];
	userInputRowsAndCols(rows, cols);

	char** matrix = new char* [rows];
	for (size_t row = 0; row < rows; row++)
	{
		matrix[row] = new char[cols];
	}

	for (size_t row = 0; row < rows; row++)
	{
		cin.getline(str,100);
		strcpy(matrix[row], str);
	}


	for (int row = rows - 1; row >= 0; row--)
	{
		for (int col = cols - 1; col >= 0; col--)
		{
			if (!isLetter(matrix[row][col]))
				continue;
			cout << matrix[row][col];
		}
		cout << " ";
	}

	for (size_t row = 0; row < rows; row++)
	{
		delete[] matrix[row];
	}
	delete[] matrix;
	return 0;
}
