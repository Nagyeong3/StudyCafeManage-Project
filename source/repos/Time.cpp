#include "Time.h"
#include <iostream>
#include <sstream>

using namespace std;

void Time::readData(int D, int T)
{
	bY = D / 10000;
	bM = (D % 10000) / 100;
	bD = (D % 10000) % 100;
	bH = T / 100;
	bmin = T % 100;
}

void Time::insertTime()//�ð��Է��Լ�
{
	// �����ð� ���
	cout << "�����ð���";
	showTime();
		
	bY = Y;
	bM = M;
	bD = D;
	bH = H;
	bmin = min;
	
	

	cout << "��¥�� �Է����ּ��� (2022��07��21�� -> 20220721) : ";
	cin >> Date;

	Y = Date / 10000;
	M = (Date % 10000) / 100;
	D = (Date % 10000) % 100;

	cout << "�ð��� �Է����ּ��� (16��34�� -> 1634)";
	cin >> Time;

	H = Time / 100;
	min = Time % 100;

}

void Time::cleanDB()
{
	//�����

	//���ϱ�

}

void Time::leftTime(string finish)
{
	//int�κ���
	int finshT;
	stringstream ssInt(finish);
	ssInt >> finshT;

	finshT -= Time;
	string hour, min;



}

void Time::showTime()
{
	cout << Y << "��" << M / 100 << "��" << D % 100 
		<< "��\t"<<H<<"��"<< min<<"��";

}
