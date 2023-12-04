//#include <iostream>
//using namespace std;
//const int MAX_SIZE = 8;
//
//void printArr(const int arr[], size_t size)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//void swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
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
//void removeIndexInArray(int arr[], size_t size, int index)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		if (i >= index && i != size - 1)
//		{
//			swap(arr[i], arr[i + 1]);
//		}
//		else if (i == size - 1)
//			arr[i] = -1;
//	}
//}
//
//
//int main()
//{
//	cout << "Write " << MAX_SIZE << " numbers:" << endl;
//	int arr[MAX_SIZE];
//	fillArray(arr, MAX_SIZE);
//
//	cout << "Choose index to remove:" << endl;
//	int index;
//	cin >> index;
//
//	removeIndexInArray(arr, MAX_SIZE, index);
//	printArr(arr, MAX_SIZE);
//	return 0;
//}