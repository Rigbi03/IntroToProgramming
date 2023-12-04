#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


int main()
{

	char str[4];
	//while (true)
		//cout << strcpy(str, "gay");
	cout << strcpy(str, "abc");
	cout << strcpy_s(str, 4, "abc");
}