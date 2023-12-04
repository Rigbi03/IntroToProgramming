// Zadacha 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int absoluteValue(int n)
{
    if (n < 0)
        return -n;
    return n;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << absoluteValue(n);
}

