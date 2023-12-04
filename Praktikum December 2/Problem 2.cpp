#include <iostream>
using namespace std;
const int ALPHABET_SIZE = 26;

int strLen(const char* arr)
{
	if (arr == nullptr)
		return 0;

	size_t count = 0;
	while (*arr != '\0')
	{
		count++;
		arr++;
	}
	return count;
}

bool arrayIsValid(char* arr)
{
	char* index = arr;
	while (*index != '\0')
	{
		if (*index < 'a' || *index > 'z')
			return false;
		index++;
	}
	return true;
}

void userInput(char* arr)
{
	while (!arrayIsValid(arr))
	{
		cout << "Enter a valid word/sentence > ";
		cin.getline(arr, ALPHABET_SIZE);
	}
}

//bool allCharsAreUnique(char* arr)
//{
//	char* beginChar = arr;
//	char* compareChar = arr + 1;
//	while (*beginChar != '\0')
//	{
//		while (*compareChar != '\0')
//		{
//			if (*beginChar == *compareChar)
//				return false;
//			compareChar++;
//		}
//
//		beginChar++;
//		compareChar = beginChar + 1;
//	}
//	return true;
//}
bool uniqueWord(const char* arr)
{
	bool alphabet[ALPHABET_SIZE];
	for (int i = 0; i < ALPHABET_SIZE; i++)
		alphabet[i] = false;

	int i = 0;
	while(arr[i] != '\0')
	{
		if (!alphabet[arr[i] - 'a'])
			alphabet[arr[i] - 'a'] = true;
		else
			return false;
		i++;
	}
	return true;
}


int main()
{
	char arr[ALPHABET_SIZE];
	cin.getline(arr, ALPHABET_SIZE);
	
	userInput(arr);
	cout << uniqueWord(arr);
	

	return 0;
}