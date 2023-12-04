// Zadacha 15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int numberOfLines = n * 2 - 1;
    int numberOfColumns;
    if (n % 2 == 0)
    {
        numberOfColumns = (n * 5) / 2;
    }
    else
    {
        numberOfColumns = n * 5;
    }
    std::cout << "number of columns " << numberOfColumns << std::endl;
    for (int line = 1; line <= numberOfLines; line++)
    {
        for (int column = 1; column <= numberOfColumns; column++)
        {
            if (line < n)
            {
                if (column <= line)
                {
                    std::cout << column << " ";
                }
                else if (column > (numberOfColumns - line))
                {
                    std::cout << ((numberOfColumns - column) + 1) << " ";
                }
                else
                {
                    std::cout << " ";
                }
            }
            else if (line == n)
            {
                if (column <= line || column >= (numberOfColumns - line))
                {
                    std::cout << column << " ";
                }
                else
                {
                    std::cout << "-";
                }
            }
            //else
            //{
            //    if (column <= (line - n) || column >= (numberOfColumns - line))
            //    {
            //        std::cout << column << " ";
            //    }
            //    else
            //    {
            //        std::cout << " ";
            //    }
            //}
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
