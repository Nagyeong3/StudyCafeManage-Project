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

void Time::insertTime()//시간입력함수
{
	// 이전시간 기록
	cout << "이전시간은";
	showTime();
		
	bY = Y;
	bM = M;
	bD = D;
	bH = H;
	bmin = min;
	
	

	cout << "날짜를 입력해주세요 (2022년07월21일 -> 20220721) : ";
	cin >> Date;

	Y = Date / 10000;
	M = (Date % 10000) / 100;
	D = (Date % 10000) % 100;

	cout << "시간을 입력해주세요 (16시34분 -> 1634)";
	cin >> Time;

	H = Time / 100;
	min = Time % 100;

}

void Time::cleanDB()
{
	//정기권

	//단일권

}

void Time::leftTime(string finish)
{
	//int로변경
	int finshT;
	stringstream ssInt(finish);
	ssInt >> finshT;

	finshT -= Time;
	string hour, min;



}

void Time::showTime()
{
	cout << Y << "년" << M / 100 << "월" << D % 100 
		<< "일\t"<<H<<"시"<< min<<"분";

}
