#include <iostream>
using namespace std;
const int SIZE = 1024;

double distanceBetweenTwoPoints(double x1, double y1, double x2, double y2)
{
	double dx = x1 - x2;
	double dy = y1 - y2;

	return sqrt(dx * dx + dy * dy);
}
double findMultipleDistances(const double arrOfX[], const double arrOfY[], size_t size)
{
	double distance = 0;
	for (int i = 0; i < size - 1; i++)
	{
		distance += distanceBetweenTwoPoints(arrOfX[i], arrOfY[i], arrOfX[i + 1], arrOfY[i + 1]);
	}
	return distance;
}
double setPrecisionTo2Digits(double number)
{
	number *= 1000;
	int roundedN = number;

	if (roundedN % 10 >= 5)
	{
		roundedN /= 10;
		roundedN++;
		return roundedN / 100.0;
	}

	return roundedN / 1000.0;
}

int main()
{
	int size1 = 0, size2 = 0;
	double distance1 = 0, distance2 = 0, x, y;
	double arrOfSize1X[SIZE], arrOfSize1Y[SIZE], arrOfSize2X[SIZE], arrOfSize2Y[SIZE];

	while (size1 < 1 || size1 > 512)
	{
		cout << "size1 > ";
		cin >> size1;
	}

	for (int i = 0; i < size1; i++)
	{
		cin >> x >> y;
		arrOfSize1X[i] = x;
		arrOfSize1Y[i] = y;
	}

	distance1 += findMultipleDistances(arrOfSize1X, arrOfSize1Y, size1);
	distance1 = setPrecisionTo2Digits(distance1);

	while (size2 < 1 || size2 > 512)
	{
		cout << "size2 > ";
		cin >> size2;
	}

	for (int i = 0; i < size2; i++)
	{
		cin >> x >> y;
		arrOfSize2X[i] = x;
		arrOfSize2Y[i] = y;
	}

	distance2 += findMultipleDistances(arrOfSize2X, arrOfSize2Y, size2);
	distance2 = setPrecisionTo2Digits(distance2);

	if (distance1 == distance2)
	{
		if (distance1 == (int)distance1)
			cout << "true" << endl << distance1 << ",00";
		else cout << "true" << endl << distance1;
	}
	else cout << "false";

	return 0;
}