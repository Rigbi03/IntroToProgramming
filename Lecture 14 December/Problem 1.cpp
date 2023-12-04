#include <iostream>
using namespace std;
const size_t MAX_SIZE = 3;

void test(int** matrix, int rows, int cols) // dinamichno zadelena
{

}

void test(int matrix[][30]) // statichno zadelena
{

}

int main()
{
	/*
	  00 , 01 , 02 , 03
	  10 , 11 , 12 , 13
	  20 , 21 , 22 , 23
	  30 , 31 , 32 , 33
	  -> 00 10 01 20 11 02 30 21 12 03 | 31 22 13 32 23 33
	*/


	/* MAX_SIZE = 4;
	  int matrix[MAX_SIZE][MAX_SIZE] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};*/

	int matrix[MAX_SIZE][MAX_SIZE] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};



	//print top-left half + middle diagonal
	for (size_t diag = 0; diag < MAX_SIZE; diag++)
	{
		for (size_t row = diag, col = 0; col <= diag && row >= 0; row--, col++)
		{
			cout << matrix[row][col] << " ";
		}
	}

	//print bottom-right half
	for (size_t maxrow = MAX_SIZE - 1, mincol = 1; mincol <= MAX_SIZE - 1; mincol++)
	{
		for (size_t row = maxrow, col = mincol; col <= maxrow && row >= mincol; row--, col++)
		{
			cout << matrix[row][col] << " ";
		}
	}
	return 0;
}