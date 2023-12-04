#include <iostream>
using namespace std;

int myStrLen(const char* inputString)
{
	unsigned int length = 0;

	while (*inputString)
		length++, inputString++;

	return length;
}

void strConCat(char* dest, const char* source)
{
	dest += myStrLen(dest);

	while (*source)
	{
		*dest = *source;
		dest++, source++;
	}
	*dest = '\0';

}

int main()
{
	char str[100];
	cin.getline(str, 100);
	const char* str2 = "world!";
	strConCat(str, str2);
	cout << str;
	return 0;
}