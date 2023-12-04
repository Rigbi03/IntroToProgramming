//#include <iostream>
//using namespace std;
//const int SIZE = 32;
//
//unsigned int toBinary(unsigned int n)
//{
//	int result = 0;
//	int mult = 1;
//	while (n != 0)
//	{
//		if (n % 2 == 1)
//			result += mult;
//		mult *= 10;
//		n /= 2;
//	}
//	return result;
//}
//
//void fillArray(int arr[], size_t size, int num)
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (num == 0) break;
//		arr[size - i - 1] = num % 10;
//		num /= 10;
//	}
//}
//
//void printArr(const int arr[], size_t SIZE)
//{
//	for (size_t i = 0; i < SIZE; i++)
//	{
//		cout << arr[i];
//	}
//}
//
//int main()
//{
//	unsigned int num;
//	cin >> num;
//	num = toBinary(num);
//	int initialArray[SIZE] = { 0 };
//	fillArray(initialArray, SIZE, num);
//
//
//	printArr(initialArray, SIZE);
//	return 0;
//}