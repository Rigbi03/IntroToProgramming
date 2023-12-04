#include <iostream>
using namespace std;

void printAllWordsInASentence(const char* arr)
{
	while (*arr != '\0')
	{
		if (*arr == ' ')
			cout << endl;
		else cout << *arr;
		arr++;
	}
}

int main()
{
	printAllWordsInASentence("Hello World I am");
	return 0;
}