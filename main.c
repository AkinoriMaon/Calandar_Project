// Visual Studio 2019���� �ۼ��� �ڵ��Դϴ�.

#include <Windows.h>
#include "common.h"
#include "Calandar_Info.h"
#include "cusManager.h"

// ���� ���� ��ũ�� �Լ� ����
#define BLACK 0
#define BLUE 9
#define RED 12
#define YELLOW 14
#define WHITE 15

// �����Ͽ� ���� ��ũ�� �Լ� ����
#define NEWYEAR (calendar.month == 1 && day == 1)
#define INDEPENDENCE_MOVEMENT_DAY (calendar.month == 3 && day == 1)
#define CHILDRENS_DAY (calendar.month == 5 && day == 5)
#define MEMORIAL_DAY (calendar.month == 6 && day == 6)
#define NATIONAL_LIBERATION_DAY (calendar.month == 8 && day == 15)
#define NATIONAL_FOUNDATION_DAY_OF_KOREA (calendar.month == 10 && day == 3)
#define HANGUL_PROCLMATION_DAY (calendar.month == 10 && day == 9)
#define CHRISTMAS (calendar.month == 12 && day == 25)

extern Calendar calendar;
extern int month_day[12];

void SetColor(unsigned short color, unsigned short back) // WORD�� unsigned short�� ���ǵǾ� �ֱ� ����
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | (back << 4)); // ������ ���ÿ�, ���ڻ� ����
}

void ScreenOut()
{
	int cal[6][7]; // �޷� 2���� �迭
	int i = 0;
	int day = 1;
	int count = 0;

	system("cls");

	printf("%d�� %d�� \n\n", calendar.year, calendar.month);

	SetColor(RED, WHITE);
	fputs("Sun", stdout);

	SetColor(BLACK, WHITE);
	fputs("   Mon   Tus   Wen   Thu   Fri   ", stdout);

	SetColor(BLUE, WHITE);
	puts("Sat");

	SetColor(BLACK, WHITE);
	for (i = 0; i < calendar.week_day - 1; i++)
	{
		printf("      ");
		count++;
	}

	for (i = 0; i < month_day[calendar.month - 1]; i++)
	{
		if ((count == 0 || NEWYEAR || INDEPENDENCE_MOVEMENT_DAY || CHILDRENS_DAY || MEMORIAL_DAY ||
			NATIONAL_LIBERATION_DAY || NATIONAL_FOUNDATION_DAY_OF_KOREA || HANGUL_PROCLMATION_DAY ||
			CHRISTMAS) && (calendar.day == day)) // �����ϰ� ���� ������ ���� ��ġ�� ��
		{
			SetColor(RED, YELLOW);
		}
		else if (count == 0 || NEWYEAR || INDEPENDENCE_MOVEMENT_DAY || CHILDRENS_DAY || MEMORIAL_DAY ||
			NATIONAL_LIBERATION_DAY || NATIONAL_FOUNDATION_DAY_OF_KOREA || HANGUL_PROCLMATION_DAY ||
			CHRISTMAS) // �����ϸ�
		{
			SetColor(RED, WHITE);
		}
		else if ((count == 6) && (calendar.day == day)) // ����ϰ� ���� ������ ���� ��ġ�� ��
		{
			SetColor(BLUE, YELLOW);
		}
		else if (count == 6) // ����ϸ�
		{
			SetColor(BLUE, WHITE);
		}
		else if (calendar.day == day) // ���� ������ ��
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW << 4);
		}
		printf("%3d", day);

		SetColor(BLACK, WHITE);
		fputs("   ", stdout);
		
		day++;
		count++;

		if (count >= 7)
		{
			puts("");
			count = 0;
		}
	}
}

int ShowMenu()
{
	int menu;

	puts("\n");
	puts("------- Menu -------");
	puts("1. Change Year");
	puts("2. Change Month");
	puts("3. Change Day");
	puts("4. Change All");
	puts("5. Exit");
	puts("");

	scanf_s("%d", &menu);
	ClearInputBuffer();
	system("cls");

	switch (menu)
	{
		case YEAR:
			ChangeYear();
			break;
		case MONTH:
			ChangeMonth();
			break;
		case DAY:
			ChangeDay();
			break;
		case ALL:
			ChangeAllData();
			break;
		case EXIT:
			return 0;
		default:
			puts("�߸��� �޴� �����Դϴ�.");
			break;
	}
}

int main()
{
	ChangeAllData();

	while (1)
	{
		Calendar standard = { 1, 1, 1, MONDAY };
		int date_num = 1;
		int i = 0;

		for (i = standard.year; i < calendar.year; i++)
		{
			IsLeapYear(month_day, i);

			if (month_day[1] != 28) // �����̶��,
			{
				date_num += 366;
			}
			else
			{
				date_num += 365;
			}
		}

		for (i = 0; i < calendar.month - standard.month; i++)
		{
			date_num += month_day[i];
		}

		switch (date_num % 7) // ������ �Ͽ����̹Ƿ� %7�� ���� ��, 1�� ������ �������̴�.
		{
		case 0: // SATURDAY�� ���� Ƚ���� ���ؼ� 0���� ������ �� ��� �̰͸� ���������� 0���� ó����
			calendar.week_day = SUNDAY;
			break;
		case 1:
			calendar.week_day = MONDAY;
			break;
		case 2:
			calendar.week_day = TUESDAY;
			break;
		case 3:
			calendar.week_day = WEDNSDAY;
			break;
		case 4:
			calendar.week_day = THURSDAY;
			break;
		case 5:
			calendar.week_day = FRIDAY;
			break;
		case 6:
			calendar.week_day = SATURDAY;
			break;
		default:
			puts("Error! That's not normal data!");
			break;
		}

		IsLeapYear(month_day, calendar.year);
		ScreenOut();
		if (ShowMenu() == 0)
		{
			puts("���α׷��� �����մϴ�.");
			break;
		}
	}
	
	return 1;
}