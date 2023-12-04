// Praktikum 28 October.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

int sumInInterval(int n, int m)
{
	if (((m - n) + 1) % 2 == 0)
	{
		return (n + m) * (((m - n) + 1) / 2);
	}
	else
	{
		return ((n + m) * (((m - n) + 1) / 2)) + ((n + m) / 2);
	}
}

int absoluteValue(int n)
{
	if (n < 0)
	{
		return -n;
	}
	return n;

}

double distBetweenTwoPoints(double p1x, double p1y, double p2x, double p2y)
{
	double dx = p1x - p2x;
	double dy = p1y - p2y;

	return sqrt(dx * dx + dy * dy);
}

bool triangleIsValid(double ab, double ac, double bc)
{
	return (ab + bc >= ac && ac + ab >= bc && bc + ac >= ab);
}

double perimeterOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double ab = distBetweenTwoPoints(x1, y1, x2, y2);
	double ac = distBetweenTwoPoints(x1, y1, x3, y3);
	double bc = distBetweenTwoPoints(x2, y2, x3, y3);

	if (triangleIsValid(ab, ac, bc))
	{
		double perimeter = ab + ac + bc;
		return perimeter / 1.000;
	}
	return -1;
}

double areaOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double halfPerimeter = perimeterOfTriangle(x1, y1, x2, y2, x3, y3) / 2;
	double ab = distBetweenTwoPoints(x1, y1, x2, y2);
	double ac = distBetweenTwoPoints(x1, y1, x3, y3);
	double bc = distBetweenTwoPoints(x2, y2, x3, y3);

	if (triangleIsValid(ab, ac, bc))
	{
		return sqrt(halfPerimeter * (halfPerimeter - ab) * (halfPerimeter - ac) * (halfPerimeter - bc));
	}
	return -1;
	
}

bool isDigit(char ch)
{
	return (ch >= 48 && ch <= 57);
}

char toUpper(char ch)
{
	if (ch >= 97 && ch <= 122)
	{
		return (ch - 32);
	}
	return 32;
}

int main()
{
	//Problem 1
	/*int n, m;
	std::cin >> n >> m;
	std::cout << sumInInterval(n, m);*/

	//Problem 2
	/*int n, m;
	std::cin >> n;
	std::cout << absoluteValue(n);*/
	
	//Problem 3
	double x1, y1, x2, y2, x3, y3;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	std::cout << std::setprecision(5) << perimeterOfTriangle(x1, y1, x2, y2, x3, y3) ;
	//std::cout << areaOfTriangle(x1, y1, x2, y2, x3, y3);

	//Problem 4
	/*char ch;
	std::cin >> ch;
	if (isDigit(ch))
	{
		std::cout << "true";
	}
	else  std::cout << "false";*/

	//Problem 5
	/*char ch;
	std::cin >> ch;
	std::cout << toUpper(ch);*/

	return 0;
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
