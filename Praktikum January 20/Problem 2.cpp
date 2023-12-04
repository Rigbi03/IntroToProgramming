#include <iostream>
using namespace std;



bool findWay(int** arrayOfCoordinates, bool** labyrinth, int rows, int cols, int x = 0, int y = 0, int steps = 0)
{
	
	if (x > rows - 1 || y > cols - 1) return false;

	if (!labyrinth[x][y]) return false;

	if (x == rows - 1 && y == cols - 1 && labyrinth[x][y]) return true;

	arrayOfCoordinates[0][steps] = x;
	arrayOfCoordinates[1][steps] = y;

	return findWay(arrayOfCoordinates, labyrinth, rows, cols, x, y + 1, steps + 1) ||
		findWay(arrayOfCoordinates, labyrinth, rows, cols, x + 1, y, steps + 1);
}

void findWalks(int** arrayOfCoordinates,bool** labyrinth, int rows, int cols,int& walks, int x = 0, int y = 0)
{
	if ((x == rows - 1 && y == cols - 1) ||
		x > rows-1 || y > cols-1) return;

	else if (x + 1 < rows  && findWay(arrayOfCoordinates, labyrinth, rows, cols, x + 1, y) &&
		y + 1 < cols  && findWay(arrayOfCoordinates, labyrinth, rows, cols, x, y + 1)) walks++;

		findWalks(arrayOfCoordinates, labyrinth, rows, cols,walks, x, y + 1);
		findWalks(arrayOfCoordinates, labyrinth, rows, cols,walks, x + 1, y);
}

int findRouteLength(int** matrix,int rows, int cols)
{
	int count = 1;
	int possibleCoordinates = rows * cols;
		for (size_t col = 0; col < possibleCoordinates; col++)
		{
			if (matrix[0][col] == rows-1  && matrix[0][col] == cols-1 )
				return count + 1;
			count++;	
		}
	return -1;
}

int main()
{


	int rows, cols, walks = 1;
	cin >> rows >> cols;

	int** arrayOfCoordinates = new int* [2];
	int possibleCoordinates = cols * rows;

	for (size_t row = 0; row < 2; row++)
	{
		arrayOfCoordinates[row] = new int[possibleCoordinates] {0};
	}

	bool** labyrinth = new bool* [rows];
	for (size_t row = 0; row < rows; row++)
	{
		labyrinth[row] = new bool[cols];
	}

	for (size_t row = 0; row < rows; row++)
	{
		for (size_t col = 0; col < cols; col++)
		{
			cin >> labyrinth[row][col];
		}
	}

	

	cout << "Is there route: " << findWay(arrayOfCoordinates, labyrinth, rows, cols, walks) << endl;

	int length = findRouteLength(arrayOfCoordinates, rows, cols);
	//if (length != -1) cout << "Length: " << length << endl;

	findWalks(arrayOfCoordinates, labyrinth, rows, cols, walks);

	

	
	cout << "Walks: " << walks << endl;


	for (size_t row = 0; row < 2; row++)
	{
		delete[] arrayOfCoordinates[row];
	}
	delete[] arrayOfCoordinates;

	for (size_t row = 0; row < rows; row++)
	{
		delete[] labyrinth[row];
	}
	delete[] labyrinth;


	return 0;
}