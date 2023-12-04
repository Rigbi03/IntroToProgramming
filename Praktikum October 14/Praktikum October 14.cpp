// Praktikum October 14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //Problem 1
    /*int day;
    std::cin >> day;

    switch (day)
    {
    case 1: std::cout << "Monday"; break;
    case 2: std::cout << "Tuesday"; break;
    case 3: std::cout << "Wednesday"; break;
    case 4: std::cout << "Thursday"; break;
    case 5: std::cout << "Friday"; break;
    case 6: std::cout << "Saturday"; break;
    case 7: std::cout << "Sunday"; break;
    default: std::cout << "Invalid Day"; break;*/

    //Problem 2
    /*int a, b, c;
    std::cin >> a >> b >> c;

    bool positiveSidesCheck = (a > 0) && (b > 0) && (c > 0);
    
    if (!positiveSidesCheck)
    {
    std::cout << "Invalid sides.";
    }
    else if (a + b < c || a + c < b || b + c < a )
    {
        std::cout << "This triangle does not exist";
    }    
    else
    {
        std::cout << "This triangle exists";
    }*/

    //Problem 3
    /*int leftInterval, rightInterval, number;
    std::cin >> leftInterval >> rightInterval >> number;

    if (number < leftInterval || number > rightInterval)
    {
        std::cout  << "The number out of the given interval.";
    }
    else if (number == leftInterval || number == rightInterval)
    {
        std::cout << "The number is within the given interval. The interval is closed";
    }
    else 
    { 
        std::cout << "The number is within the given interval. The interval is open."; 
    }*/

    //Problem 4
    //int c = 10;
    //std::cout << ((c == 6) && (c / !c)); // False && False -> False -> 0 (Checking stops after c==6, because it is False)
    //std::cout << ((c == 6) || (c / !c)); // False && Invalid (Can't divide by 0) "Or" check until the end

    //Problem 5
    //int c = 5;
    //if (c += c -= 5) // Not a valid check, -= isn't a bool operation
    //    std::cout << 42;
    //else
    //    std::cout << c; // First operation is c -= 5, because = is a right operator, then is makes c = 0 , 0 += 0 = 0

    //Problem 6
    /*int number;
    std::cin >> number;

    bool validNumber = number >= 0 && number <= 12;

    if (!validNumber)
    {
        std::cout << "Invalid Number. Please enter a number between 0 and 12";
    }
    else
    {
             switch (number)
            {
            case 0: std::cout << "0 ";
            case 2: std::cout << "2 ";
            case 4: std::cout << "4 ";
            case 6: std::cout << "6 ";
            case 8: std::cout << "8 ";
            case 10: std::cout << "10 ";
            case 12: std::cout << "12 "; break;
            case 1: std::cout << "1 ";
            case 3: std::cout << "3 ";
            case 5: std::cout << "5 ";
            case 7: std::cout << "7 ";
            case 9: std::cout << "9 ";
            case 11: std::cout << "11";
            }
        }
    }*/

    //Problem 7
    /*int a, b, c;
    std::cin >> a >> b >> c;
    bool positiveNumbersCheck = (a > 0) && (b > 0) && (c > 0);

    if (!positiveNumbersCheck) 
    {
        std::cout << "Invalid Numbers. Please enter positive numbers.";
    }
    else
    {
        std::cout << (a / b) + (b / c) + (c / a);
    }*/

    

    //Problem 8
    int a, b, c;
    std::cin >> a >> b >> c;

    /*if (a > b && a > c)
    {
        if (b > c)
        {
            std::cout << c << b << a;
        }
        else
        {
            std::cout << b << c << a;
        }
    }
    else if (b > a && b > c)
    {
        if (a > c)
        {
            std::cout << c << a << b;
        }
        else
        {
            std::cout << a << c << b;
        }
    }
    else
    {
        if (a > b)
        {
            std::cout << b << a << c;
        }
        else
        {
            std::cout << a << b << c;
        }
    }*/
int smallest1 = (a > b) ? b : a;
int smallest2 = (a > c) ? a : c;
int smallest = (smallest1 > smallest2) ? smallest1 : smallest2;
int middle1 = (b > c) ? c : b;
int middle = (smallest1 > middle1) ? smallest1 : middle1;
int biggest = (smallest2 > middle1) ? smallest2 : middle1;
std::cout << smallest << middle << biggest;

    //Problem 9
 /*   int radius,coordinatex, coordinatey;
    std::cin >> radius >> coordinatex >> coordinatey;

    bool isInside = (coordinatex * coordinatex) + (coordinatey * coordinatey) <= radius * radius;
    
    if (!isInside)
    {
        std::cout << "Out of the circle";
    }
    else
    {
        std::cout << "In the circle";
    }*/

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
