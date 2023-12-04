//#include <iostream>
//using namespace std;
//const int MAX_SIZE = 20;
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
//int occurrencesOfNumber(const int arr[], size_t size, int number)
//{
//	int count = 0;
//	for (size_t i = 0; i < size; i++)
//	{
//		if (arr[i] == number)
//			count++;
//	}
//	return count;
//}
//
//void printAllOccurrences(const int arr[], size_t size)
//{
//	for (int i = 0; i <= 19; i++)
//	{
//		cout << "The number " << i << " is found " << occurrencesOfNumber(arr, size, i) << " times." << endl;
//	}
//}
//
//int main()
//{
//	cout << "Write " << MAX_SIZE << " numbers:" << endl;
//	int arr[MAX_SIZE];
//	fillArray(arr, MAX_SIZE);
//	printAllOccurrences(arr, MAX_SIZE);
//	return 0;
//}