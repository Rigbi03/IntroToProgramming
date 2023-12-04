// Zadacha 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    double temp = sqrt(n);

    for (int i = 2; i <= temp; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool arePrimesKnumbers(int n, int k)
{
    double temp = sqrt(n);
    int count = 0;
    
    for (int j = 2; j <= n; j++)
    {
        if (isPrime(j) && (n % j) == 0)
            count++;
    }
    
    return count == k;
}

int findAllPrimeDenominators(int a, int b, int k)
{
    int count = 0;
    
    for (int i = a; i <= b; i++)
    {
        if (arePrimesKnumbers(i, k))
            count++;      
    }

    return count;
}

int main()
{
    int a, b, k;
    std::cin >> a >> b >> k;
    std::cout << findAllPrimeDenominators(a, b, k);
}
