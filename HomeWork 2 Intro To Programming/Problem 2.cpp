#include <iostream>
using namespace std;
char currentPossibleStep = 'a' - 1;
int stepsMade = 0;
bool hist[26] = { 0 };

void deleteMountain(char** mountain, int rows)
{
	for (size_t row = 0; row < rows; row++)
	{
		delete[] mountain[row];
	}
	delete[] mountain;
}

void deleteArrayOfCoordinates(int** arrayOfCoordinates)
{
	for (size_t row = 0; row < 2; row++)
	{
		delete[] arrayOfCoordinates[row];
	}
	delete[] arrayOfCoordinates;
}

void userInputRowsAndCols(int& rows, int& cols)
{
	while (rows < 1 && cols < 1)
	{
		cout << "Enter Rows and Columns >";
		cin >> rows >> cols;
	}
}

void userInputMountainInsideFor(char** mountain, int row, int cols, int& x, int& y)
{
	for (int col = 0; col < cols; col++)
	{
		cin >> mountain[row][col];
		if (mountain[row][col] == 'S')
		{
			x = row;
			y = col;
		}
	}
}

void userInputMountain(char** mountain, int rows, int cols, int& x, int& y)
{
	cout << "Enter Mountain > " << endl;
	for (int row = 0; row < rows; row++)
	{
		userInputMountainInsideFor(mountain, row, cols, x, y);
	}
}

bool locationIsMarked(int x, int y, int** arrayOfCoordinates, int possibleLocations)
{

	for (int j = 0; j < possibleLocations; j++)
	{
		if (arrayOfCoordinates[0][j] == x && arrayOfCoordinates[1][j] == y) return true;
	}
	return false;

}

bool findWay(char** mountain, int rows, int cols, int x, int y, int** arrayOfCoordinates, int possibleLocations)
{
	if (x < 0 || y < 0 || x > rows - 1 || y > cols - 1)
		return false;

	if (locationIsMarked(x, y, arrayOfCoordinates, possibleLocations))
		return false;

	if (currentPossibleStep != 'z' + 1 && mountain[x][y] == 'E')
	{
		return false;
	}
	else if (mountain[x][y] == 'E')
	{
		cout << "Route Exists" << endl;
		return true;
	}

	if (mountain[x][y] > currentPossibleStep)
		return false;

	arrayOfCoordinates[0][stepsMade] = x;
	arrayOfCoordinates[1][stepsMade] = y;
	cout << "Current Position: " << mountain[x][y] << " Coords: " << x << " " << y << endl;

	currentPossibleStep = mountain[x][y] + 1;
	if (mountain[x][y] == 'S')
		currentPossibleStep = 'a';
	stepsMade++;



	return findWay(mountain, rows, cols, x + 1, y, arrayOfCoordinates, possibleLocations) ||
		findWay(mountain, rows, cols, x, y + 1, arrayOfCoordinates, possibleLocations) ||
		findWay(mountain, rows, cols, x - 1, y, arrayOfCoordinates, possibleLocations) ||
		findWay(mountain, rows, cols, x, y - 1, arrayOfCoordinates, possibleLocations);
}

int main()
{
	int rows = 0, cols = 0, x, y;

	userInputRowsAndCols(rows, cols);

	char** mountain = new char* [rows];
	for (size_t row = 0; row < rows; row++)
	{
		mountain[row] = new char[cols];
	}

	int** arrayOfCoordinates = new int* [2];
	int possibleLocations = rows * cols;

	for (size_t i = 0; i < 2; i++)
	{
		arrayOfCoordinates[i] = new int[possibleLocations];
	}

	userInputMountain(mountain, rows, cols, x, y);

	cout << findWay(mountain, rows, cols, x, y, arrayOfCoordinates, possibleLocations) << endl;
	cout << "Steps: " << --stepsMade << endl;

		
	deleteMountain(mountain, rows);
	deleteArrayOfCoordinates(arrayOfCoordinates);

	return 0;
}