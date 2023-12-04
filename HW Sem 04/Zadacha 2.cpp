// Zadacha 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int numberOfDigits(int n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n /= 10;
    }
    return count;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << numberOfDigits(n);
}


