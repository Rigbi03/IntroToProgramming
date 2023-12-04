//#include <iostream>
//using namespace std;
//const int MAX_SIZE = 8;
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
//void swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void reverseFirstHalf(int arr[], size_t size)
//{
//	for (size_t i = 0; i < size / 4; i++)
//	{
//		swap(arr[i], arr[(size / 2) - i - 1]);
//	}
//}
//
//void printArr(const int arr[], size_t size)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		cout << arr[i];
//	}
//	cout << endl;
//}
//
//int main()
//{
//	cout << "write " << MAX_SIZE << " numbers:" << endl;
//	int arr[MAX_SIZE];
//	fillArray(arr, MAX_SIZE);
//	reverseFirstHalf(arr, MAX_SIZE);
//	printArr(arr, MAX_SIZE);
//	return 0;
//}