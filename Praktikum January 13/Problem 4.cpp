#include <iostream>
using namespace std;



bool findWay(bool** labyrinth, int rows, int cols, int x = 0, int y = 0)
{
	if (x < 0 || y < 0 || x > rows - 1 || y > cols - 1) return false;

	if (!labyrinth[x][y]) return false;

	if (x == rows - 1 && y == cols - 1 && labyrinth[x][y]) return true;

	labyrinth[x][y] = 0; //Marked

	return findWay(labyrinth, rows, cols, x + 1, y) ||
		findWay(labyrinth, rows, cols, x, y + 1) ||
		findWay(labyrinth, rows, cols, x - 1, y) ||
		findWay(labyrinth, rows, cols, x, y - 1);
}

int main()
{
	int n, m;
	cin >> n >> m;

	bool** labyrinth = new bool* [n];
	for (size_t i = 0; i < n; i++)
	{
		labyrinth[i] = new bool[m];
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0;  j < m;  j++)
		{
			cin >> labyrinth[i][j];
		}
	}
	
	cout << findWay(labyrinth, n, m);

	for (size_t i = 0; i < n; i++)
	{
		delete[] labyrinth[i];
	}
	delete[] labyrinth;
	return 0;
}