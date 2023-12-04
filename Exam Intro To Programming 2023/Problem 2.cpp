#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

//4 5
//# m e m o
//# f o o t
//d a d d h
//t o p r e



void userInputForSize(int& rows, int& cols)
{
	while (rows < 1 || cols < 1 || rows > 100 || cols > 100)
	{
		cout << "Enter natural numbers lower than 101 for N and M >";
		cin >> rows >> cols;
	}
}

void userInputForMatrixInsideFor(char** matrix, int row, int cols)
{
	for (size_t col = 0; col < cols; col++)
	{
		cin >> matrix[row][col];
	}
}

void userInputForMatrix(char** matrix, int rows, int cols)
{
	cout << "Enter Matrix > " << endl;
	for (int row = 0; row < rows; row++)
	{
		userInputForMatrixInsideFor(matrix, row, cols);
	}
}

void deleteMatrix(char** matrix, int rows)
{
	for (size_t row = 0; row < rows; row++)
	{
		delete[] matrix[row];
	}
	delete[] matrix;
}

bool myStrCmp(const char* word1, const char* word2)
{
	while (*word1 || *word2)
	{
		if (*word1 != *word2)
			return false;

		word1++, word2++;
	}

	if (*word1 != *word2)
		return false;

	return true;
}

bool findWord( char** matrix, const char* word, int rows, int cols, int x = 0, int y = 0)
{
	if (x < 0 || y < 0 || x >= rows || y >= cols)
		return false;

	if (matrix[x][y] == '#')
		return false;

	if (matrix[x][y] != *word)
		return false;

	if (matrix[x][y] == *word && *(word + 1) == '\0')
		return true;

	word++;

	return findWord(matrix, word, rows, cols , x + 1, y) ||
		findWord(matrix, word, rows, cols, x - 1, y) ||
		findWord(matrix, word, rows, cols, x, y + 1) ||
		findWord(matrix, word, rows, cols, x, y - 1);
	
}

void searchForWordInsideFor(char** matrix, const char* word, int rows, int cols, int x, bool& foundWord)
{
	for (size_t y = 0; y < cols; y++)
	{
		if (findWord(matrix, word, rows, cols, x, y))
		{
			foundWord = true;
			return;
		}
	}
}

bool searchForWord(char** matrix,const char* word, int rows, int cols )
{
	bool foundWord = false;

	for (size_t x = 0; x < rows; x++)
	{
		searchForWordInsideFor(matrix, word, rows, cols, x, foundWord);

		if (foundWord) 
			return true;
	}

	return foundWord;
}

int main()
{
	int rows = 0, cols = 0;
	userInputForSize(rows, cols);

	char** matrix = new char* [rows];
	for (size_t row = 0; row < rows; row++)
	{
		matrix[row] = new char[cols];
	}
	userInputForMatrix(matrix, rows, cols);
	
	char word[100];
	cout << "Enter Word with less than 101 symbols >" << endl;
	cin.ignore();
	cin.getline(word, 100);


	cout << searchForWord(matrix, word, rows, cols);

	deleteMatrix(matrix, rows);
	return 0;
}