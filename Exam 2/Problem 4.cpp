#include <iostream>
#pragma warning (disable : 4996)
using namespace std;


void deleteMatrix(char** matrix, int rows)
{
	for (int row = 0; row < rows; row++)
	{
		delete[] matrix[row];
	}
	delete[] matrix;
}

void userInputCols(char**& matrix, int row, int cols)
{
	for (int col = 0; col < cols; col++)
	{
		cout << "Enter a symbol on coordinates " << row << " " << col << " > ";
		cin >> matrix[row][col];
	}
}

void userInput(char**& matrix, int rows, int cols)
{
	for (int row = 0; row < rows; row++)
	{
		userInputCols(matrix, row, cols);
	}

}

void checkDownwardsForRepetitions(char** matrix, int col, int rows, char ch, int count, bool& repetitionOfSymbolsFound)
{
	int tempcount = 0;
	for (int row = 0; row < rows; row++)
	{
		if (tempcount == count)
			repetitionOfSymbolsFound = true;
		else if (matrix[row][col] == ch)
			tempcount++;
		else tempcount = 0;
	}

	if (tempcount == count)
		repetitionOfSymbolsFound = true;
}

bool areThereSameSymbols(char** matrix, int rows, int cols, char ch, int count )
{	
	bool repetitionOfSymbolsFound = false;
	for (int col = 0; col < cols; col++)
	{
		checkDownwardsForRepetitions(matrix, col, rows, ch, count, repetitionOfSymbolsFound);
	}
	return repetitionOfSymbolsFound;
}

//int main()
//{
//	int rows = 0, cols = 0, count = 0;
//	char ch;
//	while (rows < 1 || rows > 1024 || cols < 1 || cols > 1024)
//	{
//		cout << "Enter size for rows between 1 and 1024 > ";
//		cin >> rows;
//		cout << "Enter size for columns between 1 and 1024 > ";
//		cin >> cols;
//	}
//
//	while (count < 1)
//	{
//		cout << "Enter a natural number for repetitions > ";
//			cin >> count;
//	}
//
//	cout << "Enter a symbol to look for repetitions > ";
//	cin >> ch;
//
//	char** matrix = new char* [rows];
//	for (size_t row = 0; row < rows; row++)
//	{
//		matrix[row] = new char[cols];
//	}
//
//	userInput(matrix, rows, cols);
//
//	cout << areThereSameSymbols(matrix, rows, cols, ch, count);
//
//	deleteMatrix(matrix, rows);
//	
//	return 0;
//}