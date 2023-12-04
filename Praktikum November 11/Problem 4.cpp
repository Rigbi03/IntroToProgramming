//#include <iostream>
//using namespace std;
//const int MAX_SIZE = 20;
//// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
//
//void fillArray(int arr[], size_t size)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		int a;
//		cin >> a;
//		arr[i] = a;
//	}
//}
//
//bool isNumberInArray(const int arr[], size_t size, int number)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		if (arr[i] == number)
//			return true;
//	}
//	return false;
//}
//
//int findTheMissingNumber(const int arr[], size_t size)
//{
//	for (int i = 0; i <= 20; i++)
//	{
//		if (!isNumberInArray(arr, size, i))
//			return i;
//	}
//	return -1;
//}
//
//int main()
//{
//	cout << "Write " << MAX_SIZE << " numbers:" << endl;
//	int arr[MAX_SIZE];
//	fillArray(arr, MAX_SIZE);
//	cout << "The missing is: " << findTheMissingNumber(arr, MAX_SIZE) << endl;
//	return 0;
//}