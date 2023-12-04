#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
int currentGroup = 1;


int mystrlen(const char* str)
{
	int count = 0;
	while (*str)
	{
		count++, str++;
	}
	return count;
}

bool isValidBackPack(const char* str)
{
	while (*str)
	{
		if (!(*str >= 'A' && *str <= 'Z') && !(*str >= 'a' && *str <= 'z'))
			return false;
		str++;
	}
	return true;
}

void findRepeatingGiftsInsideFor(char** arrayOfBackPacks, size_t backPackIndex, int length, int& prioritySum, bool& foundRepeatingGift, size_t firstHalfIndex)
{
	for (size_t secondHalfIndex = (length / 2); secondHalfIndex < length; secondHalfIndex++)
	{
		if (arrayOfBackPacks[backPackIndex][firstHalfIndex] == arrayOfBackPacks[backPackIndex][secondHalfIndex])
		{
			std::cout << "Repeating Gift in backpack number " << backPackIndex + 1 << " is: " << arrayOfBackPacks[backPackIndex][firstHalfIndex] << endl;
			prioritySum += (arrayOfBackPacks[backPackIndex][firstHalfIndex] < 'a') ? (arrayOfBackPacks[backPackIndex][firstHalfIndex] - 'A' + 27) : arrayOfBackPacks[backPackIndex][firstHalfIndex] - 'a' + 1;
			foundRepeatingGift = true;
			return;
		}
	}
}

void findRepeatingGiftsAndPriority(char** arrayOfBackPacks, size_t backPackIndex, int& prioritySum)
{
	int length = mystrlen(arrayOfBackPacks[backPackIndex]);
	bool foundRepeatingGift = false;
	if (length % 2 != 0)
	{
		std::cout << "Error: Odd number of gifts in backpack number: " << backPackIndex + 1 << " !!" << endl;
		return;
	}

	for (size_t firstHalfIndex = 0; firstHalfIndex < length / 2; firstHalfIndex++)
	{
		findRepeatingGiftsInsideFor(arrayOfBackPacks, backPackIndex, length, prioritySum, foundRepeatingGift, firstHalfIndex);
		if (foundRepeatingGift) return;
	}
}

void fillBackPacks(char**& arrayOfBackPacks, int numberOfBackPacks)
{
	for (size_t backPackIndex = 0; backPackIndex < numberOfBackPacks; backPackIndex++)
	{
		std::cout << "Enter gifts > ";
		char gifts[100];
		cin.getline(gifts, 80);

		if (strlen(gifts) > 80)
		{
			std::cout << "You have entered too many gifts, please re-enter " << endl;
			cin.ignore();
			backPackIndex--;
			continue;
		}
		else if (!isValidBackPack(gifts))
		{
			std::cout << "You have entered invalid gifts, please re-enter " << endl;
			cin.ignore();
			backPackIndex--;
			continue;
		}

		strcpy(arrayOfBackPacks[backPackIndex], gifts);
	}
}

void compareSecondAndThird(char** arrayOfBackPacks,size_t backPackIndex, size_t secondBackPackIndex, size_t backpack3Len,bool& foundIndentificator)
{
	for (size_t thirdBackPackIndex = 0; thirdBackPackIndex < backpack3Len; thirdBackPackIndex++)
	{
		if (arrayOfBackPacks[backPackIndex + 1][secondBackPackIndex] == arrayOfBackPacks[backPackIndex + 2][thirdBackPackIndex])
		{
			std::cout << "Group " << currentGroup << " has identificator " << arrayOfBackPacks[backPackIndex+1][secondBackPackIndex] << endl;
			foundIndentificator = true;
			return;
		}
	}
}

void compareFirstAndSecond(char** arrayOfBackPacks, size_t backPackIndex, size_t firstBackPackIndex, size_t backpack2Len, size_t backpack3Len,bool& foundIndentificator)
{
	for (size_t secondBackPackIndex = 0; secondBackPackIndex < backpack2Len; secondBackPackIndex++)
	{
		if (arrayOfBackPacks[backPackIndex][firstBackPackIndex] == arrayOfBackPacks[backPackIndex + 1][secondBackPackIndex])
		{
			compareSecondAndThird(arrayOfBackPacks,backPackIndex, secondBackPackIndex, backpack3Len, foundIndentificator);
			if (foundIndentificator) return;
		}
	}
}

void compareBackPacksInGroup(char** arrayOfBackPacks, size_t backPackIndex, size_t backpack1Len, size_t backpack2Len, size_t backpack3Len)
{
	for (size_t firstBackPackIndex = 0; firstBackPackIndex < backpack1Len; firstBackPackIndex++)
	{
		bool foundIndentificator = false;
		compareFirstAndSecond(arrayOfBackPacks, backPackIndex, firstBackPackIndex, backpack2Len, backpack3Len, foundIndentificator);
		if (foundIndentificator) return;
	}
}

void groupBackPacksAndFindIdentificators(char** arrayOfBackPacks, size_t numberOfBackPacks)
{
	for (size_t backPackIndex = 0; backPackIndex < numberOfBackPacks; backPackIndex+=3,currentGroup++) // currentGroup global variable
	{
		if (backPackIndex + 3 > numberOfBackPacks) return;

		size_t backpack1Len = mystrlen(arrayOfBackPacks[backPackIndex]);
		size_t backpack2Len = mystrlen(arrayOfBackPacks[backPackIndex + 1]);
		size_t backpack3Len = mystrlen(arrayOfBackPacks[backPackIndex + 2]);
		
		compareBackPacksInGroup(arrayOfBackPacks, backPackIndex, backpack1Len, backpack2Len, backpack3Len);	
	}
}

int main()
{
	int numberOfBackPacks = 0;
	int prioritySum = 0;

	while (numberOfBackPacks < 1)
	{
		std::cout << "Enter natural number for backpacks > ";
		cin >> numberOfBackPacks;
		cin.ignore();
	}

	char** arrayOfBackPacks = new char* [numberOfBackPacks];
	for (size_t i = 0; i < numberOfBackPacks; i++)
	{
		arrayOfBackPacks[i] = new char[80];
	}

	fillBackPacks(arrayOfBackPacks, numberOfBackPacks);

	for (size_t backpack = 0; backpack < numberOfBackPacks; backpack++)
	{
		findRepeatingGiftsAndPriority(arrayOfBackPacks, backpack, prioritySum);
	}

	std::cout << "Priority: " << prioritySum << endl;

	groupBackPacksAndFindIdentificators(arrayOfBackPacks, numberOfBackPacks);

	for (size_t i = 0; i < numberOfBackPacks; i++)
	{
		delete[] arrayOfBackPacks[i];
	}

	delete[] arrayOfBackPacks;

	return 0;
}