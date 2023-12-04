#include <iostream>
using namespace std;
const int INFINITE_ROOTS = -1;
const int NO_ROOTS = 1;
const int ONE_SOLUTION = 0;

double findLinearRoot(int a, int b, int& valid)
{
	if (a == 0 && b == 0)
	{
		valid = INFINITE_ROOTS;
		return 0;
	}
	else if (a == 0)
	{
		valid = NO_ROOTS;
		return 0;
	}
	else
	{
		valid = ONE_SOLUTION;
		double aCopyDouble = a;
		double bCopyDouble = b;
		return (-bCopyDouble) / aCopyDouble;
	}
}


int main()
{
	int valid = 0, a , b;
	cin >> a >> b;
	cout << findLinearRoot(a, b, valid) << endl << valid;
	
	
	
	/*double a, b;
	cout << "ax + b = 0" << endl;
	a = userInput(a);
	setPrecisionTo2Digits(a);
	b = userInput(b);
	setPrecisionTo2Digits(b);

	double x = linearEquationSolver(a, b);
	cout << x << endl;
	cout << setPrecisionTo2Digits(linearEquationSolver(a, b));
	double userInput(int number)
{
	while (number < 1)
	{
		cout << "Enter Whole Number > ";
		cin >> number;
	}
	return number;
}
double linearEquationSolver(int a, int b)
{
	return (-b) / a;
}*/

	return 0;
}