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
//bool isItSorted(const int arr[], size_t size)
//{
//	for (size_t i = 0; i < size - 1; i++)
//	{
//		if (arr[i] > arr[i + 1])
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	cout << "Write " << MAX_SIZE << " numbers:" << endl;
//	int arr[MAX_SIZE];
//	fillArray(arr, MAX_SIZE);
//	if (isItSorted(arr, MAX_SIZE))
//		cout << "The Array is Sorted.";
//	else cout << "The Array is NOT Sorted.";
//	return 0;
//}