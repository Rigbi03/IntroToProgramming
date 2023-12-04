#include <iostream>
#include<cstring>
#pragma warning (disable : 4996)
using namespace std;
int myStrLen(const char* str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	
	return count;
}

void deleteArray(char** array, size_t length)
{
	for (int row = 0; row <= length; row++)
	{
		delete[] array[row];
	}
	delete[] array;
}

void getSuffix(char**& array, size_t length, const char* str)
{
	for (int row = 0; row <= length; row++)
	{
		const char* strCopy = str;
		for (int col = 0; col <= length; col++)
		{
			array[row][col] = *strCopy;
			strCopy++;
		}
		str++;
		strCopy = str;
	}
}

int main()
{
	char str[1024];
	cin.getline(str, 1024);
	size_t length = myStrLen(str);
	
	char** array = new char* [length];
	for (size_t row = 0; row <= length; row++)
	{
		array[row] = new char [length + 1 - row];
	}

	getSuffix(array, length, str);

	for (int row = (int)length; row >= 0; row--)
	{
		char* letter = array[row];
		while (*letter)
		{
			cout << *letter;
			letter++;
		}
		cout << endl;
	}

	/*for (size_t row = 0; row < length; row++)
	{
		delete[] array[row];
	}
	delete[] array;*/

	return 0;
}