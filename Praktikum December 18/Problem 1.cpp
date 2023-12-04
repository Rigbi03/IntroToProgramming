#include<iostream>
using namespace std;


int main()
{
	int n = 0, input, sum = 0;
	while(n < 1)
	cin >> n;
	int* array = new int[n];

	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		array[i] = input;
		if (i % 2 == 0)
			sum += input;
	}

	cout << sum;
	delete[] array;
	return 0;
}