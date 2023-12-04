#include <iostream>	
#pragma warning (disable : 4996)
#include <cstring>
using namespace std;

bool isValidChar(const char str)
{
	return str >= 'a' && str <= 'z' ||
		str >= '0' && str <= '9' ||
		str >= 'A' && str <= 'Z';
}

int countWordsInAString(const char* str, int& longestWordLength)
{
	int numberOfWhiteSpaces = 0;
	int currentLength = 0;

	while (*str)
	{
		if (!isValidChar(*str))
		{
			numberOfWhiteSpaces++;
			longestWordLength	 = (longestWordLength < currentLength) ? currentLength : longestWordLength;
			currentLength = 0;
			
		}
		currentLength++;
		str++;
	}
	
	return numberOfWhiteSpaces + 1;
}

int main()
{
	char str[1024];
	cin.getline(str, 1024);
	int longestWordLength = 0;
	int numberOfWords = countWordsInAString(str, longestWordLength);

	char** matrix = new char* [numberOfWords];
	for (size_t i = 0; i < numberOfWords; i++)
	{
		matrix[i] = new char[longestWordLength];
	}

	for (size_t word = 0; word < numberOfWords; word++)
	{
		char* letter = matrix[0];
		//while()
	}

	
	for (size_t i = 0; i < numberOfWords; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}