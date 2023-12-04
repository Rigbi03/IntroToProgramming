#include <iostream>
#include <cstring>
#pragma warning (disable : 4996)
using namespace std;
const int MAX_LENGTH = 1024;
bool lengthError = false;

bool isNumber(const char symbol)
{
	return (symbol >= '0' && symbol <= '9');
}

void removeNumbers(char*& string)
{
	char newStr[MAX_LENGTH];
	int newStrIter = 0;
	while (*string)
	{
		if (isNumber(*string))
		{
			string++;
			continue;
		}
		newStr[newStrIter++] = *string;
		string++;
	}
	newStrIter++;
	newStr[newStrIter] = '\0';
	string = newStr;
}

void concatSymbols_s(char* str1, int length, char* str2)
{
	removeNumbers(str2);

	if ((strlen(str1) + strlen(str2)) > length)
	{
		lengthError = true;
		return;
	}

	str1 += strlen(str1);
	while (*str2)
	{
		if (isNumber(*str2))
		{
			str2++;
			continue;
		}
		*str1 = *str2;
		str1++, str2++;
	}
	str1--;
	*str1 = '\0';
}


//int main()
//{
//	char str1[MAX_LENGTH], str2[MAX_LENGTH];
//	int lengthOfstr1 = 0;
//
//	cout << "Enter first string > ";
//	cin.getline(str1, MAX_LENGTH);
//
//	while (lengthOfstr1 < 1)
//	{
//		cout << "Enter a natural number for length of string 1 > ";
//		cin >> lengthOfstr1;
//	}
//	cin.ignore();
//
//	cout << "Enter second string > ";
//	cin.getline(str2, MAX_LENGTH);
//
//	concatSymbols_s(str1, lengthOfstr1, str2);
//
//	if (lengthError)
//		cout << "Not enough space";
//	else cout << str1;
//
//	return 0;
//}
