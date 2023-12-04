// Zadacha 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //Problem 3
    int number;
    std::cin >> number;
    int copyOfNumber = number;
    int numberOfDigits = 0;

    //Check for number of Digits
    while (copyOfNumber != 0)
    {
        numberOfDigits++;
        copyOfNumber /= 10;
    }

    copyOfNumber = number;
    bool isNumberOfDigitsEven = true;
    int a = 0;
    int b = 0;
    int step = 1;

    if (numberOfDigits % 2 != 0)
    {
        isNumberOfDigitsEven = false;
    }

    if (isNumberOfDigitsEven == true)
    {
        int copyOfNumberOfDigits = numberOfDigits;
        for (int j = 1; j <= numberOfDigits; j++)
        {
            for (int i = copyOfNumberOfDigits; i >= 1; i--)
            {

                int currentLastDigit = copyOfNumber % 10;

                if (i == (numberOfDigits / 2) || i == (numberOfDigits / 2) + 1)
                {
                    copyOfNumber /= 10;
                    continue;
                }
                else if (i == 1)
                {
                    std::cout << currentLastDigit;
                }

                copyOfNumber /= 10;
            }

            copyOfNumber = number;
            copyOfNumberOfDigits--;
        }
        std::cout << ", ";
    }
    else
    {
        /*int copyOfNumberOfDigits = numberOfDigits;
        for (int j = 1; j == numberOfDigits; j++)
        {
            for (int i = copyOfNumberOfDigits; i >= 1; i--)
            {
                int currentLastDigit = copyOfNumber % 10;

                if (i == 1)
                {
                    std::cout << currentLastDigit;
                }

                copyOfNumber /= 10;
            }
            copyOfNumberOfDigits--;
        }*/
        std::cout << "zashto stigna tuk?";
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
