#pragma once


class Time {


public:


	//시간변수 int로 부족.. 날짜와 시간 두개로 저장? 아니면 더 큰 자료형?
	int Date, Time;

	insertTime(); //시간입력함수
	cleanDB(); //정기권,단일권 정리
	showTime(); //시간출력 함수

};