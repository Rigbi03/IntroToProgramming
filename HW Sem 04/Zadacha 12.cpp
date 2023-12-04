// Zadacha 12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isTheCharacterANumber(char ch)
{
    return (ch >= 48 && ch <= 57);
}

int main()
{
    char ch;
    std::cin >> ch;
    
    if (isTheCharacterANumber(ch))
    {
        std::cout << "true";
    }
    else
    {
        std::cout << "false";
    }
}

