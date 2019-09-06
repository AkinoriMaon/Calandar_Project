// Visual Studio 2019���� �ۼ��� �ڵ��Դϴ�.

#include "common.h"
#include "Change_Data.h"

void ChangeYear()
{
	while (1)
	{
		puts("------- Calendar System ------- \n");

		fputs("Input data (Ex : 2019) : ", stdout);
		scanf_s("%d", &calendar.year);
		ClearInputBuffer();

		IsLeapYear(month_day, calendar.year);

		if (calendar.year < 1)
		{
			ErrorMessage();
			continue;
		}
		else
		{
			break;
		}
	}
}

void ChangeMonth()
{
	while (1)
	{
		puts("------- Calendar System ------- \n");

		fputs("Input data (Ex : 08) : ", stdout);
		scanf_s("%d", &calendar.month);
		ClearInputBuffer();

		if (calendar.month < 1 || calendar.month > 12)
		{
			ErrorMessage();
			continue;
		}
		else
		{
			break;
		}
	}
}

void ChangeDay()
{
	while (1)
	{
		puts("------- Calander System -------");

		fputs("Input data (Ex : 30) : ", stdout);
		scanf_s("%d", &calendar.day);
		ClearInputBuffer();

		if (calendar.day < 1 || calendar.day > month_day[calendar.month - 1])
		{
			ErrorMessage();
			continue;
		}
		else
		{
			break;
		}
	}
}

void ChangeAllData()
{
	while (1)
	{
		puts("------- Calendar System ------- \n");

		fputs("Input data (Ex : 2019 08 30) : ", stdout);
		scanf_s("%d %d %d", &calendar.year, &calendar.month, &calendar.day);
		ClearInputBuffer();
		
		IsLeapYear(month_day, calendar.year);

		// �ּ����� �����˻縦 �����ؾ� ��. ���� �ϴ� ���ظ��� ǥ���ϴ� ���� ��ǥ�� �����Ѵ�.
		if (calendar.year < 1)
		{
			ErrorMessage();
			continue;
		}
		else if (calendar.month < 1 || calendar.month > 12)
		{
			ErrorMessage();
			continue;
		}
		else if (calendar.day < 1 || calendar.day > month_day[calendar.month - 1])
		{
			ErrorMessage();
			continue;
		}
		else
		{
			break;
		}
	}
}