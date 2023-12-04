#include <iostream>
using namespace std;
bool ysenIsGoingBack = false;

void userInputSize(int& size)
{
	while (size < 1)
	{
		cout << "Enter natural number for size >";
		cin >> size;
	}
}

void userInputHomeAndDest(int& homex, int& homey, int& destx, int& desty, int size)
{
	while (homex < 1 || homex > size - 1 || homey < 0 || homey > size - 1 ||
		destx < 1 || destx > size - 1 || desty < 0 || desty > size - 1)
	{
		cout << "Enter home coordinates >";
		cin >> homex >> homey;
		cout << "Enter destination coordinates >";
		cin >> destx >> desty;
	}
}

void userInputMaxVolume(int& maxVolume)
{
	while (maxVolume < 0)
	{
		cout << "Enter maxVolume >";
		cin >> maxVolume;
	}
}

void userInputSquareMatrixInsideFor(int** matrix, int row, int size)
{
	for (size_t col = 0; col < size; col++)
	{
		cin >> matrix[row][col];
	}
}

void userInputSquareMatrix(int** matrix, int size)
{
	for (int row = 0; row < size; row++)
	{
		userInputSquareMatrixInsideFor(matrix, row, size);
	}
}

void deleteSquareMatrix(int** matrix, int size)
{
	for (size_t row = 0; row < size; row++)
	{
		delete[] matrix[row];
	}
	delete[] matrix;
}

void printSquareMatrixInsideFor(int** matrix, int row, int size)
{
	for (size_t col = 0; col < size; col++)
	{
		cout << matrix[row][col] << " ";
	}
}

void printSquareMatrix(int** matrix, int size)
{
	for (int row = 0; row < size; row++)
	{
		printSquareMatrixInsideFor(matrix, row, size);
		cout << endl;
	}
}

void printRoute(int* route, int size)
{
	int length = size * size * 2;
	for (size_t i = 0; i < length; i += 2)
	{
		if (!route[i] && !route[i + 1])
			return;

		cout << "(" << route[i] << "," << route[i + 1] << ") ";
	}
}


bool foundRoute(int** matrix, int size, int startx, int starty, int endx, int endy, int currentx, int currenty, int volume,
	int maxVolume, int* route, int moves = 0)
{
	if (currentx < 0 || currenty < 0 || currentx > size - 1 || currenty > size - 1)
		return false;

	if (volume + matrix[currentx][currenty] > maxVolume || volume + matrix[currentx][currenty] < 0)
		return false;

	volume += matrix[currentx][currenty];
	matrix[currentx][currenty] = maxVolume + 1; //Marked
	route[moves] = currentx;
	route[moves + 1] = currenty;
	moves += 2;
	
	if (currentx == endx && currenty == endy && !ysenIsGoingBack)
	{
		matrix[startx][starty] = 0;
		matrix[endx][endy] = 0;
		moves -= 2;
		ysenIsGoingBack = true;
		return foundRoute(matrix, size, endx, endy, startx, starty, currentx, currenty, volume, maxVolume, route, moves);
	}

	if (currentx == endx && currenty == endy && ysenIsGoingBack)
		return true;

	

	return foundRoute(matrix, size, startx, starty, endx, endy, currentx + 1, currenty, volume, maxVolume, route, moves) ||
		foundRoute(matrix, size, startx, starty, endx, endy, currentx - 1, currenty, volume, maxVolume, route, moves) ||
		foundRoute(matrix, size, startx, starty, endx, endy, currentx, currenty + 1, volume, maxVolume, route, moves) ||
		foundRoute(matrix, size, startx, starty, endx, endy, currentx, currenty - 1, volume, maxVolume, route, moves);

}

int main()
{
	int size = 0;
	userInputSize(size);

	int** matrix = new int* [size];
	for (size_t row = 0; row < size; row++)
	{
		matrix[row] = new int[size];
	}
	userInputSquareMatrix(matrix, size);

	int homex = -1, homey = -1, destx = -1, desty = -1;
	userInputHomeAndDest(homex, homey, destx, desty, size);

	int volume = 0, maxVolume = -1;
	userInputMaxVolume(maxVolume);

	int* route = new int[size * size * 2] {-1};

	cout << "Is there Route: " << foundRoute(matrix, size, homex, homey, destx, desty, homex, homey, volume, maxVolume, route) << endl;

	printRoute(route, size);

	delete[] route;
	deleteSquareMatrix(matrix, size);
	return 0;
}