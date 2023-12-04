#include <iostream>
#include <cstring>
#pragma warning ( disable: 4996 )
using namespace std;

// aaabcaadcsmaabbbbsaaacc
// 101010541010142110105555210101044

void printArr(const int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void initializeHist(int* hist, const char* inputString)
{
	while (*inputString)
	{
		hist[*inputString - 'a']++, inputString++;
	}
}

void initializeArrayCopyOfString(int* array, const char* inputString, int stringLength, const int* hist)
{
	for (size_t i = 0; i < stringLength; i++)
	{
		array[i] = hist[*inputString - 'a'];
		inputString++;
	}
}

char intToChar(int number)
{
	return number % 10 + '0';
}

int invertNumber(int number)
{
	int newNumber = 0;

	while (number != 0)
	{
		(newNumber *= 10) += number % 10;
		number /= 10;
	}

	return newNumber;
}

int countDigits(int num)
{
	int count = 0;

	while (num != 0)
	{
		count++;
		num /= 10;
	}

	return count;
}

int validSpace(const int* hist)
{
	int spaceNeeded = 0;

	for (size_t index = 0; index < 26; index++)
	{
		spaceNeeded += hist[index] * countDigits(hist[index]);
	}

	if (spaceNeeded > 1024)
		return 0;
	else
		return spaceNeeded;
}

void putLargeNumberInString(char* inputString, int number)
{
	while (number != 0)
	{
		*inputString = intToChar(number % 10);
		number /= 10;
		inputString++;
	}
}

void fixArray(int* array, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] += (array[i] == 0) ? 0 : 1;
	}
}

void inplace(const int* arrayCopyOfString, char* inputString)
{
	int length = strlen(inputString);
	
	for (size_t i = 0; i < length; i++)
	{
		int currentNum = arrayCopyOfString[i];
		int currentDigits = countDigits(currentNum);

		inputString += currentDigits;
		while(currentNum > 0)
		{
			inputString--;
			*inputString = (currentNum % 10) + '0';
			currentNum /= 10;
		}
		inputString += currentDigits;

		//if (arrayCopyOfString[i] >= 10)
		//{

		/*	int number = invertNumber(arrayCopyOfString[i]);

			if (arrayCopyOfString[i] % 100 == 0)
			{
				putLargeNumberInString(inputString, number);
				inputString++;
				*inputString = '0';
				inputString++;
				*inputString = '0';
				inputString++;
			}
			else if (arrayCopyOfString[i] % 10 == 0)
			{
				putLargeNumberInString(inputString, number);
				inputString++;
				*inputString = '0';
				inputString++;
			}
			else
			{
				putLargeNumberInString(inputString, number);
				inputString += countDigits(number);
			}
		}
		else
		{
			*inputString = intToChar(arrayCopyOfString[i]);
			inputString++;
		}*/
	}

	*inputString = '\0';
}

bool convertToStrNumber(char* inputString, const int* hist, const int* arrayCopyOfString)
{
	if (!validSpace(hist))
		return false;

	inplace(arrayCopyOfString, inputString);

	return true;
}

int main()
{

	char inputString[1024];
	cin.getline(inputString, 1024);

	int hist[26] = { 0 };
	initializeHist(hist, inputString);
	

	int stringLength = strlen(inputString);
	int* arrayCopyOfString = new int[stringLength];
	initializeArrayCopyOfString(arrayCopyOfString, inputString, stringLength, hist);

	convertToStrNumber(inputString, hist, arrayCopyOfString);

	cout << inputString << endl;

	return 0;
}