#include <iostream>
using namespace std;
const int MAX_SIZE = 1024;

void myStrCopy(const char* source, char* dest)
{
	if (source == nullptr || dest == nullptr)
		return;

	while (*source != '\0')
	{
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
}

void removeLetter(char* str, char letter)
{
	char newString[MAX_SIZE];
	int newstriter = 0;
	while (*str)
	{
		if (*str == letter)
		{
			str++;
		}
		else
		{
			newString[newstriter++] = *str;
			str++;
		}

	}
	newString[newstriter++] = '\0';
	myStrCopy(str, newString);
}

void toLower(char* str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		else if (*str < 'a' || *str > 'z')
			removeLetter(str, *str);
		str++;
	}
	cout << str << endl;
}

void fillHist(const char* str, int hist[])
{
	while (*str)
	{
		if (*str < 'a' || *str > 'z')
			str++;
		else 
		{
			hist[*str - 'a']++;
			str++;
		}
	}
}

void sortStr(int hist[], char* newString)
{
	for (int i = 0; i < 26; i++)
	{
		while (hist[i] != 0)
		{
			*newString = i + 'a';
			newString++;
			hist[i]--;
		}
	}
	*newString = '\0';

}
int main()
{	
	char str[MAX_SIZE];
	char newString[MAX_SIZE];
	int hist[26] = {0};
	cin.getline(str, MAX_SIZE);
	toLower(str);
	fillHist(str,hist);
	sortStr(hist, newString);
	cout << newString;
	return 0;
}