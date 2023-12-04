#include <iostream>
using namespace std;


int main()
{
	char arr[] = "hello";
	char* pointer = arr;
	char* secondPointer = arr;

	*pointer = '6';
	std::cout << *pointer;

	return 0;
}