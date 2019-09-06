// Visual Studio 2019에서 작성된 코드입니다.

#include "common.h"
#include "cusManager.h"

void ClearInputBuffer()
{
	while (getchar() != '\n');
}

void ErrorMessage()
{
	puts("Your data was wrong! Please check it again.");
	getchar();
	system("cls");
}

void IsLeapYear(int* month_day, int year)
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		month_day[1] = 29;
	}
	else if (year % 400 == 0)
	{
		month_day[1] = 29;
	}
	else
	{
		month_day[1] = 28;
	}
}