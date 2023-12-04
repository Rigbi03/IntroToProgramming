#include <iostream>
#include <stdlib.h>
#include<windows.h>   
using namespace std;

int main()
{
	int i = 1;
	while (i > 0)
	{
		cout << std::string(i, ' ') << " ----------------------" << endl;
		cout << std::string(i, ' ') << "|  |   |   |    |  |   \\\ """ << endl;
		cout << std::string(i, ' ') << "|__|___|___|____|__|____\\\ """ << endl;
		cout << std::string(i, ' ') << "|               |  |     \\\ """ << endl;
		cout << std::string(i, ' ') << "`-(o)(o)------------(o)--'  " << endl;
		i++;
		Sleep(10);
		system("CLS");
	}
	return 0;
}