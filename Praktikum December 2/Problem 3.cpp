#include <iostream>
using namespace std;
const int MAX_SIZE = 1024;

size_t strLen(const char* arr)
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

bool stringIsPolindrome(const char* arr)
{
	size_t length = strLen(arr);
	const char* endChar = arr + length - 1;

	for (int i = 0; i < length / 2; i++, arr++, endChar--)
	{
		if (*arr != *endChar)
			return false;	
	}
	return true;
}

int main()
{
	char arr[MAX_SIZE];
	cin.getline(arr, MAX_SIZE);
	cout << stringIsPolindrome(arr)<< endl;
	//cout << stringIsPolindrome("hello") << endl;
	//cout << stringIsPolindrome("abcdcba") << endl;
}