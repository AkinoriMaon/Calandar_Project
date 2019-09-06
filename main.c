// Visual Studio 2019에서 작성된 코드입니다.

#include <Windows.h>
#include "common.h"
#include "Calandar_Info.h"
#include "cusManager.h"

// 색깔에 대한 매크로 함수 지정
#define BLACK 0
#define BLUE 9
#define RED 12
#define YELLOW 14
#define WHITE 15

// 국경일에 대한 매크로 함수 지정
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

void SetColor(unsigned short color, unsigned short back) // WORD가 unsigned short로 정의되어 있기 때문
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | (back << 4)); // 배경색과 동시에, 글자색 변경
}

void ScreenOut()
{
	int cal[6][7]; // 달력 2차원 배열
	int i = 0;
	int day = 1;
	int count = 0;

	system("cls");

	printf("%d년 %d월 \n\n", calendar.year, calendar.month);

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
			CHRISTMAS) && (calendar.day == day)) // 공휴일과 내가 선택한 날이 겹치는 날
		{
			SetColor(RED, YELLOW);
		}
		else if (count == 0 || NEWYEAR || INDEPENDENCE_MOVEMENT_DAY || CHILDRENS_DAY || MEMORIAL_DAY ||
			NATIONAL_LIBERATION_DAY || NATIONAL_FOUNDATION_DAY_OF_KOREA || HANGUL_PROCLMATION_DAY ||
			CHRISTMAS) // 공휴일만
		{
			SetColor(RED, WHITE);
		}
		else if ((count == 6) && (calendar.day == day)) // 토요일과 내가 선택한 날이 겹치는 날
		{
			SetColor(BLUE, YELLOW);
		}
		else if (count == 6) // 토요일만
		{
			SetColor(BLUE, WHITE);
		}
		else if (calendar.day == day) // 내가 선택한 날
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
			puts("잘못된 메뉴 선택입니다.");
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

			if (month_day[1] != 28) // 윤년이라면,
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

		switch (date_num % 7) // 기준이 일요일이므로 %7을 했을 때, 1이 나오면 월요일이다.
		{
		case 0: // SATURDAY는 공백 횟수를 위해서 0으로 설정할 수 없어서 이것만 예외적으로 0으로 처리됨
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
			puts("프로그램을 종료합니다.");
			break;
		}
	}
	
	return 1;
}