// Visual Studio 2019에서 작성된 코드입니다.

#ifndef __CALANDER_INFO_H__
#define __CALANDER_INFO_H__

typedef struct _calendar
{
	unsigned int year;
	unsigned int month;
	unsigned int day;
	int week_day; // 요일을 저장할 변수
} Calendar;

enum { SUNDAY = 1, MONDAY, TUESDAY, WEDNSDAY, THURSDAY, FRIDAY, SATURDAY };
enum {YEAR = 1, MONTH, DAY, ALL, EXIT};

#endif