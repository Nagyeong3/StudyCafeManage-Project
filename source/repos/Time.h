#pragma once
#include <string>

class Time {


public:

	int Date, Time;
	int bY, bM, bD, bH, bmin;
	int Y,M,D,H,min;

	void readData(int D,int T);
	void insertTime(); //�ð��Է��Լ�
	void cleanDB(); //�����,���ϱ� ����
	void leftTime(string finish); //�����ð� ���
	void showTime(); //�ð���� �Լ�

};