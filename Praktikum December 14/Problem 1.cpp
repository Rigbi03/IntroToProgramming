//#include <iostream>
//using namespace std;
//const int MAX_SIZE = 1024;
//
//void removeLetter(const char* str, char letter, char* newStr)
//{
//	while (*str)
//	{
//		if (*str == letter)
//		{
//			str++;
//		}
//		else 
//		{
//			*newStr = *str;
//			str++, newStr++;
//		}
//
//	}
//	*newStr = '\0';
//
//}
//
//int main()
//{
//	char str[MAX_SIZE], newStr[MAX_SIZE];
//	cin.getline(str, MAX_SIZE);
//	cout << str << endl;
//	char letter;
//	cin >> letter;
//	removeLetter(str, letter, newStr);
//	cout << newStr;
//	return 0;
//}