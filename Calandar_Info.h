// Visual Studio 2019���� �ۼ��� �ڵ��Դϴ�.

#ifndef __CALANDER_INFO_H__
#define __CALANDER_INFO_H__

typedef struct _calendar
{
	unsigned int year;
	unsigned int month;
	unsigned int day;
	int week_day; // ������ ������ ����
} Calendar;

enum { SUNDAY = 1, MONDAY, TUESDAY, WEDNSDAY, THURSDAY, FRIDAY, SATURDAY };
enum {YEAR = 1, MONTH, DAY, ALL, EXIT};

#endif