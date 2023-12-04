#include <iostream>
using namespace std;

bool isPrime(int n, int divisor = 2)
{
	if (divisor == n - 1)
		return true;
	else if (n % divisor == 0) return false;
	
	return isPrime(n, divisor + 1);
}

//int main()
//{
//	int n = 0;
//	cin >> n;
//	cout << isPrime(n);
//	return 0;
//}