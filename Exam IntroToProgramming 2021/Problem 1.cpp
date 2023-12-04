#include <iostream>
using namespace std;
const int MAXSIZE = 1024;

void userInputForSize(int& size)
{
	while (size < 1 || size >1024)
	{
		cout << "Enter natural number for size of array >";
		cin >> size;
	}
}

void userInputForArray(char* arr, int size)
{
	cout << "Enter array of colors: g, r or y >";
	for (size_t i = 0; i < size; i++)
	{
		cin >> arr[i];
		if (arr[i] != 'g' && arr[i] != 'r' && arr[i] != 'y')
		{
			cout << "You have entered invalid element, different from g/r/y, please re-enter a new element" << endl;
			i--;
		}
	}
}

void userInputForStart(int& start, int size)
{
	while (start < 0 || start > size - 1)
	{
		cout << "Enter starting index >";
		cin >> start;
	}
}

bool greenMovementIsValid(const char* arr, int index, int size)
{
	if (index + 1 >= size - 1)
	{
		return false;
	}
	return true;
}

bool yellowMovementIsValid(const char* arr, int index, int size)
{
	for (size_t i = index; i < size; i++)
	{
		if (arr[i] == 'g')
		{
			return true;
		}
	}
	return false;
}

void yellowMovement(const char* arr, int& index, int size)
{
	while (arr[index] != 'g')
		index++;
	return;
}

int yellowMovementLength(const char* arr, int index, int size)
{
	for (int i = index; i < size; i++)
	{
		if (arr[i] == 'g')
		{
			index = i - index;
			break;
		}
	}
	return index;
}

void findWayLength(const char* arr, int start, int size, int& moves)
{
	while (arr[start] != 'r')
	{
		cout << "current position: " << start << " " << arr[start] << endl;

		if (arr[start] == 'g' && greenMovementIsValid(arr, start, size))
		{
			start++;
		}
		else if (arr[start] == 'g' && !greenMovementIsValid(arr, start, size))
		{
			cout << "Error: GREEN move goes out of bounds!" << endl;
			moves = -1;
			return;
		}
		else if (arr[start] == 'y' && yellowMovementIsValid(arr, start, size))
		{
			yellowMovement(arr, start, size);
		}
		else if (arr[start] == 'y' && !yellowMovementIsValid(arr, start, size))
		{
			cout << "Error: YELLOW move goes out of bounds! No green found." << endl;
			moves = -1;
			return;
		}
		moves++;
	}
}

int recursion(const char* arr, int start, int size, int moves = 0)
{
	if (arr[start] == 'r')
		return moves;
	
	if (arr[start] == 'g')
	{
		if (greenMovementIsValid(arr, start, size))
			return recursion(arr, start + 1, size, moves + 1);
		else
		{
			cout << "Error: GREEN move goes out of bounds!" << endl;
		}
	}
	else
	{
		if (yellowMovementIsValid(arr, start, size)) 
			return recursion(arr, start + yellowMovementLength(arr, start, size), size, moves + 1);
		else
		{
			cout << "Error: YELLOW move goes out of bounds! No green found." << endl;
		}
	}
	return -1;
}

int main()
{
	int size = 0, moves = 0;
	userInputForSize(size);

	char* arr = new char[size];
	userInputForArray(arr, size);

	int start = -1;
	userInputForStart(start, size);

	//findWayLength(arr, start, size, moves);
	moves = recursion(arr, start, size);

	if (moves != -1) cout << "Moves needed: " << moves << endl;

	delete[] arr;
	return 0;
}