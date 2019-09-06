// Visual Studio 2019에서 작성된 코드입니다.

#ifndef __CHANGE_DATA_H__
#define __CHANGE_DATA_H__

#include "Calandar_Info.h"

Calendar calendar = { 1, 1, 1, MONDAY }; // 1년 1월 1일을 기준으로 초기화
int month_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 일단 2월은 평년을 기준으로 설정

void ChangeYear();
void ChangeMonth();
void ChangeDay();
void ChangeAllData();

#endif