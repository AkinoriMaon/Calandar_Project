// Visual Studio 2019���� �ۼ��� �ڵ��Դϴ�.

#ifndef __CHANGE_DATA_H__
#define __CHANGE_DATA_H__

#include "Calandar_Info.h"

Calendar calendar = { 1, 1, 1, MONDAY }; // 1�� 1�� 1���� �������� �ʱ�ȭ
int month_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // �ϴ� 2���� ����� �������� ����

void ChangeYear();
void ChangeMonth();
void ChangeDay();
void ChangeAllData();

#endif