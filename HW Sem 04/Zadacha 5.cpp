// Zadacha 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int reverse(int n)
{
    int reversedNumber = 0;

    while (n != 0)
    {
        (reversedNumber *= 10) += n % 10;
        n /= 10;
    }

    return reversedNumber;
}

int conCatReverse(int n)
{
    int newNumber = reverse(n);
    n = reverse(n);

    while (n != 0)
    {
        (newNumber *= 10) += n % 10;
        n /= 10;
    }

    return newNumber;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << conCatReverse(n);
}
