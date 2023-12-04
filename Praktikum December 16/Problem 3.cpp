#include<iostream>
using namespace std;

void userInput(int& length, int& maxValue)
{
	while ((length < 1 && length < 10000) || (maxValue < 1 && maxValue < 1000))
	{
		cout << " Enter natural number for length lower than 10000 > ";
		cin >> length;
		cout << " Enter natural number for maximum value lower than 1000 > ";
		cin >> maxValue;
	}
}

void fillArray(int*& array, int length, int maxValue, int*& hist)
{
	int inputNumber;
	for (size_t i = 0; i < length; i++)
	{
		cout << "You have to enter " << length - i << " more numbers. " << endl;
		cout << "Enter number between 0 and "<<maxValue << " > " << endl;
		cin >> inputNumber;
		if (inputNumber < 0 || inputNumber > maxValue)
		{
			i--;
			continue;	
		}
		array[i] = inputNumber;
		hist[inputNumber]++;
		cout << endl;
	}
	cout << endl;
	
}

void fillHistWith0s(int*& hist, int length)
{
	for (size_t i = 0; i <= length; i++)
	{
		hist[i] = 0;
	}
}

bool checkForPermutations(int* hist,int length, int maxValue, int* array1, int* array2)
{
	for (size_t i = 0; i < length; i++)
	{
		hist[array1[i]]--, hist[array2[i]]--;
	}

	for (size_t i = 0; i <= maxValue; i++)
	{
		if (hist[i] != 0)
			return false;
	}
	return true;
}
int main()
{
	int length = 0, maxValue = 0;
	userInput(length, maxValue);
	int* array1 = new int[length], *array2 = new int[length], *hist = new int[maxValue + 1];
	fillHistWith0s(hist,length);
	fillArray(array1, length, maxValue,hist);
	fillArray(array2, length, maxValue,hist);
	cout <<"Permutiations > " << checkForPermutations(hist, length, maxValue, array1, array2);
	delete[] array1;
	delete[] array2;
	delete[] hist;
	return 0;
}