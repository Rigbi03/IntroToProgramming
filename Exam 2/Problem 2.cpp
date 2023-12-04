#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
const int MAX_LENGTH = 1024;


bool isEven(const char symbol)
{
	return (symbol == '0' || symbol == '2' || symbol == '4' || symbol == '6' || symbol == '8');
}

bool stringIsANumber(const char* str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return false;
		str++;
	}
	return true;
}

bool od(const char* str)
{
	while (*str)
	{
		if (!isEven(*str))
			return false;
		str++;
	}
	return true;

}

//int main()
//{
//	char str[MAX_LENGTH];
//	cout << "Enter a string of only nubmers > ";
//	cin.getline(str, MAX_LENGTH);
//
//	while (!stringIsANumber(str))
//	{
//		
//		cout << "You have entered a string with other symbols!"<<endl <<" Please enter a string of only numbers > ";
//		cin.getline(str, 1024);
//	}
//
//	if (od(str))
//		cout << "True";
//	else cout << "False";
//	return 0;
//}