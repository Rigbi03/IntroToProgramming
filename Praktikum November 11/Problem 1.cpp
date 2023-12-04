//#include <iostream>
//using namespace std;
//const int MAX_SIZE = 5;
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
//bool isPalindrom(const int arr[], size_t size)
//{
//	for (size_t i = 0; i <= size / 2; i++)
//	{
//		if (arr[i] != arr[size - i - 1])
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	cout << "write " << MAX_SIZE << " numbers:" << endl;
//	int arr[MAX_SIZE];
//	fillArray(arr, MAX_SIZE);
//
//	if (isPalindrom(arr, MAX_SIZE))
//		cout << "true";
//	else cout << "false";
//
//	return 0;
//}