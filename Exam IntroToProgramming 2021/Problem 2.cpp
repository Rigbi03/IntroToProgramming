#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const char matrixOfExpr[12][6] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"plus",
	"minus",
};

void printArr(const int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << endl;
}

bool strEqual(const char* word1, const char* word2)
{
	while (*word1 && *word2)
	{

		if (*word1 != *word2)
			return false;
		word1++, word2++;
	}
	if (*word1 != *word2) return false;
	return true;
}

int toNumber(const char* word)
{
	if (strEqual(word, "zero")) return 0;
	else if (strEqual(word, "one")) return 1;
	else if (strEqual(word, "two")) return 2;
	else if (strEqual(word, "three")) return 3;
	else if (strEqual(word, "four")) return 4;
	else if (strEqual(word, "five")) return 5;
	else if (strEqual(word, "six")) return 6;
	else if (strEqual(word, "seven")) return 7;
	else if (strEqual(word, "eight")) return 8;
	else return 9;
}

bool strPrefix(const char* prefix, const char* word)
{
	while (*prefix)
	{
		if (*prefix != *word)
			return false;
		prefix++, word++;
	}
	return true;
}

bool strSuffix(const char* suffix, const char* word)
{
	word += (strlen(word) - strlen(suffix));
	return strPrefix(suffix, word);
}

bool aNumberIsPrefix(const char* inputString)
{
	for (size_t i = 0; i < 10; i++)
	{
		if (strPrefix(matrixOfExpr[i], inputString)) 
			return true;
	}

	return false;
}

bool aNumberIsSuffix(const char* inputString)
{
	for (size_t i = 0; i < 10; i++)
	{
		if (strSuffix(matrixOfExpr[i], inputString)) 
			return true;
	}

	return false;
}

bool consecutiveOperationsFound(const char* inputString)
{
	while (*inputString)
	{
		if (strPrefix(matrixOfExpr[11], inputString))
		{
			inputString += strlen(matrixOfExpr[11]);
			if (strPrefix(matrixOfExpr[11], inputString) || strPrefix(matrixOfExpr[10], inputString))
				return true;
		}
		else if (strPrefix(matrixOfExpr[10], inputString))
		{
			inputString += strlen(matrixOfExpr[10]);
			if (strPrefix(matrixOfExpr[11], inputString) || strPrefix(matrixOfExpr[10], inputString))
				return true;
		}

		inputString++;
	}
	return false;
}

bool stringIsInvalid(const char* inputString)
{
	return !aNumberIsPrefix(inputString) || !aNumberIsSuffix(inputString) || consecutiveOperationsFound(inputString);
}

int calculateExpr(const char* inputString)
{
	int currentNumber = 0, digit = 0, result = 0, arrIndex = 0;
	int* arrOfOperations = new int[strlen(inputString)] {0};
	while (*inputString)
	{
		if (strPrefix(matrixOfExpr[10], inputString))
		{
			arrOfOperations[arrIndex++] = currentNumber;
			arrOfOperations[arrIndex++] = -2;  // -1 = minus , -2 = plus
			currentNumber = 0;
			inputString += strlen(matrixOfExpr[10]) - 1;

		}
		else if (strPrefix(matrixOfExpr[11], inputString))
		{
			arrOfOperations[arrIndex++] = currentNumber;
			arrOfOperations[arrIndex++] = -1; // -1 = minus , -2 = plus
			currentNumber = 0;
			inputString += strlen(matrixOfExpr[11]) - 1;
		}

		for (size_t i = 0; i < 10; i++)
		{
			if (strPrefix(matrixOfExpr[i], inputString))
			{
				digit = toNumber(matrixOfExpr[i]);
				(currentNumber *= 10) += digit;
				inputString += strlen(matrixOfExpr[i]) - 1;
				break;
			}
		}
		inputString++;
	}

	arrOfOperations[arrIndex] = currentNumber;

	for (int i = 0; i <= arrIndex; i++)
	{
		if (arrOfOperations[i] == -1) 
			result -= arrOfOperations[++i];
		else if (arrOfOperations[i] == -2) 
			result += arrOfOperations[++i];
		else 
			result += arrOfOperations[i];
	}
	delete[] arrOfOperations;
	return result;
}

int main()
{
	int stringLength = 0;

	while (stringLength < 1)
	{
		std::cout << "Enter Length >";
		std::cin >> stringLength;
	}

	char* inputString = new char[stringLength];

	std::cout << "Enter string >";
	std::cin.ignore();
	std::cin.getline(inputString, stringLength);

	while (stringIsInvalid(inputString))
	{
		std::cout << "Incorrect input, re-enter >";
		std::cin.getline(inputString, stringLength);
	}

	std::cout << calculateExpr(inputString);
	return 0;
}