//01��, ���Žð� ����

#pragma once
#include <string>

using namespace std;

class Time {


public:

	int Date, Time;
	int bY, bM, bD, bH, bmin;
	int Y,M,D,H,min;

	void readData();
	void writeData();
	void insertTime(); //�ð��Է��Լ�
	void cleanDB(); //�����,���ϱ� ����
	string int2string(int I); 
	string leftTime(string num, string finish); //�����ð� ���
	void showTime(); //�ð���� �Լ�
	string returnTime();

};