// Zadacha 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isTheCharUpperCase(char ch)
{
    return (ch >= 65 && ch <= 90);
}

char lowerToUpper(char ch)
{
    if (isTheCharUpperCase(ch))
    {
        return (ch + 32);
    }
    return (-1);
}

int main()
{
    char ch;
    std::cin >> ch;
    std::cout << lowerToUpper(ch);
}

