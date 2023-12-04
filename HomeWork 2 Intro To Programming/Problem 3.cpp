#include <iostream>
using namespace std;
int lightLevel = 0;

int findMaxHeight(int* street, size_t buildings)
{
	int max = 0;
	for (size_t building = 0; building < buildings; building++)
	{
		max = (max < street[building]) ? street[building] : max;
	}
	return max+1;
}

void userInput(int* street, int buildings)
{
	cout << "Enter Floors > ";
	for (size_t i = 0; i < buildings; i++)
	{
		cin >> street[i];
		if (street[i] < 0)
		{
			cout << "Invalid number of Floors, re-enter! " << endl;
			i--;
		}
	}
}

int getLightedFloors(int* street, int buildings, int* arrayOfLightLevels)
{
	lightLevel += street[0] + 1;
	int lightedFloors = 0;
	for (size_t building = 0; building < buildings; building++, lightLevel--)
	{
		if (lightLevel < street[building])
		{
			lightedFloors += street[building] - lightLevel;
			lightLevel = street[building] + 1;
		}
		else if (lightLevel == street[building])
			lightLevel++;
		arrayOfLightLevels[building] = lightLevel;
	}
	return lightedFloors;
}

void drawStreetInsideFor(int* street, int buildings, size_t rows, size_t row, int* arrayOfLightLevels)
{
	for (int col = 0; col < buildings; col++)
	{
		if (rows - row >= arrayOfLightLevels[col]) cout << "\\";
		else if (arrayOfLightLevels[col - 1] < street[col] && rows - row >= arrayOfLightLevels[col-1]) cout << "*";
		else if (rows - row <= street[col]) cout << "#";	
		else cout << "-";
	}
}

void drawStreet(int* street, int buildings, int* arrayOfLightLevels)
{
	int rows = findMaxHeight(street, buildings);

	for (size_t row = 0; row < rows; row++)
	{
		drawStreetInsideFor(street, buildings, rows, row, arrayOfLightLevels);
		cout << endl;
	}
}

int main()
{
	int buildings = 0, lightedFloors = 0;
	while (buildings < 1)
	{
		cout << "Enter positive number for Buildings > ";
		cin >> buildings;
	}

	int* street = new int[buildings];
	int* arrayOfLightLevels = new int[buildings];

	userInput(street, buildings);
	
	cout << "Number of Lighter Floors is " << getLightedFloors(street,buildings, arrayOfLightLevels) << endl;

	int rows = findMaxHeight(street, buildings);

	drawStreet(street, buildings, arrayOfLightLevels);

	delete[] street;
	delete[] arrayOfLightLevels;
	return 0;
}