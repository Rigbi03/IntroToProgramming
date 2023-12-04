#include <iostream>

bool DayIsValid(unsigned int day)
{
	return (day > 0);
}

bool MonthIsValid(unsigned int month)
{
	return (month > 0 && month < 13);
}

bool isLeapYear(unsigned int year)
{
	return(/*(year % 400 == 0) && (year % 100 != 0) &&*/ (year % 4 == 0));
}

bool MonthHas28DaysAndDaysAreValid(unsigned int month, unsigned int day, unsigned int year)
{
	return ((month == 2 && DayIsValid(day) && day < 29 && !isLeapYear(year)) || (month == 2 && DayIsValid(day) && day < 30 && isLeapYear(year)));
}

bool MonthHas31DaysAndDaysAreValid(unsigned int month, unsigned int day)
{
	return ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && DayIsValid(day) && day <= 31);
}

bool MonthHas30DaysAndDaysAreValid(unsigned int month, unsigned int day)
{
	return ((month == 4 || month == 6 || month == 9 || month == 11) && DayIsValid(day) && day <= 30);
}

bool DayAndMonthAreValid(unsigned int day, unsigned month, unsigned int year)
{
	return ((MonthHas31DaysAndDaysAreValid(month, day) && DayIsValid(day) && day < 32) || (MonthHas30DaysAndDaysAreValid(month, day) && DayIsValid(day) && day < 31) || (MonthHas28DaysAndDaysAreValid(month, day, year) && DayIsValid(day) && day < 29) || MonthIsValid(month));
}

bool YearIsValid(unsigned int year)
{
	return (year > 0 || year < 2023);
}



bool DateIsValid(unsigned int day, unsigned int month, unsigned int year)
{
	return (DayAndMonthAreValid(day, month, year) && YearIsValid(year));
}

void findNextDate(unsigned int& nextDay, unsigned int& nextMonth, unsigned int& nextYear)
{
	if (DateIsValid(nextDay, nextMonth, nextYear))
	{
		if (MonthHas31DaysAndDaysAreValid(nextMonth, nextDay) && nextDay == 31)
		{
			nextDay = 1;
			if (nextMonth == 12)
			{
				nextMonth = 1;
				nextYear++;
			}
			else nextMonth++;

			return;
		}
		else if (MonthHas30DaysAndDaysAreValid(nextMonth, nextDay) && nextDay == 30)
		{
			nextDay = 1;
			nextMonth++;
			return;
		}
		else if (MonthHas28DaysAndDaysAreValid(nextMonth, nextDay, nextYear) && nextDay == 28 && !isLeapYear(nextYear))
		{
			nextMonth++;
			nextDay = 1;
			return;
		}
		else if (MonthHas28DaysAndDaysAreValid(nextMonth, nextDay, nextYear) && nextDay == 29 && isLeapYear(nextYear))
		{
			nextDay++;
			return;
		}

		nextDay++;
		return;
	}
	return;
}

int main()
{
	unsigned int day, month, year;
	std::cin >> day >> month >> year;
	unsigned int& nextDay = day;
	unsigned int& nextMonth = month;
	unsigned int& nextYear = year;
	findNextDate(nextDay, nextMonth, nextYear);
	std::cout << nextDay << ", " << nextMonth << ", " << nextYear << std::endl;
	//return 0;
}