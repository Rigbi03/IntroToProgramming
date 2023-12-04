// Zadacha 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

double setPrecisionTo3Digits(double n)
{

	n *= 10000;
	int roundedN = n;
	
	if (roundedN % 10 >= 5)
	{
		roundedN /= 10;
		roundedN++;
		return roundedN / 1000.0;
	}

	return roundedN / 10000.0;
	
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
		return setPrecisionTo3Digits(perimeter);
	}
	return -1;
}

int main()
{
	double x1, y1, x2, y2, x3, y3;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	std::cout << perimeterOfTriangle(x1, y1, x2, y2, x3, y3);
}

