// Zadacha 10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isTheCharUpperCase(char ch)
{
    return (ch >= 65 && ch <= 90);
}

int main()
{
    char ch;
    std::cin >> ch;

    if (isTheCharUpperCase(ch))
    {
        std::cout << "true";
    }
    else std::cout << "false";
}
