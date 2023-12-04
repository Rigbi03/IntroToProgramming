// Zadacha 14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	int numberOfLines = (n * 2) - 1;

	for (int line = 1; line <= numberOfLines; line++)
	{
		for (int column = 1; column <= n; column++)
		{
			if (line <= n)
			{
				if ((n - column) + 1 > line)
				{
					std::cout << " ";
				}
				else if ((n - column) + 1 == line)
				{
					while ((column - n) != line)
					{
						if (column < n)
						{
							std::cout << (n - column);
						}
						else if (column == n)
						{
							std::cout << line;
						}
						else
						{
							std::cout << (column - n);
						}
						column++;
					}
					break;
				}
			}
			else
			{
				if (column == n)
				{
					std::cout << (n - line + 4);
				}
				else
				{
					std::cout << " ";
				}
			}
		}
		std::cout << std::endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
