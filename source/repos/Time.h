#pragma once
#include <string>

class Time {


public:

	int Date, Time;
	int bY, bM, bD, bH, bmin;
	int Y,M,D,H,min;

	void readData();
	void writeData();
	void insertTime(); //시간입력함수
	void cleanDB(); //정기권,단일권 정리
	string leftTime(string num, string finish); //남은시간 계산
	void showTime(); //시간출력 함수
	string returnTime()

};